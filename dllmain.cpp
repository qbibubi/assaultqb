#include "include/console.h"

BOOL WINAPI hookedSwapBuffers(HDC hdc)
{
    // hook shenanigans

    return SwapBuffers(hdc);
}

DWORD __stdcall Thread(LPVOID param)
{
    // threading shenaningans
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
