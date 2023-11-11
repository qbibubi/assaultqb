#include "include/console.h"


Console console;

BOOL WINAPI hookedSwapBuffers(HDC hdc)
{
    // hook shenanigans

    return SwapBuffers(hdc);
}

DWORD __stdcall Thread(LPVOID param)
{
    console.init();
    while (true)
    {
        console.printInfo();
        if (GetAsyncKeyState(VK_INSERT) & 1)
        {
            break;
        }
    }
    console.exit();
    
    FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(param), 0);
}
    
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, 0, Thread, hModule, NULL, NULL);
        DisableThreadLibraryCalls(hModule);

    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
