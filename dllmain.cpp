#include "include/gui.h"
#include <cstdint>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {  
        uint32_t hModule = reinterpret_cast<uint32_t>(GetModuleHandleA(NULL));
        uint32_t glContext = *reinterpret_cast<uint32_t*>(hModule + 0x585880);
        uint32_t glWindow = *reinterpret_cast<uint32_t*>(hModule + 0x585870);
    
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

        // Setup Platform/Renderer backends
        ImGui_ImplSDL2_InitForOpenGL(reinterpret_cast<SDL_Window *>(glWindow), reinterpret_cast<void *>(glContext));
        ImGui_ImplOpenGL3_Init();
    }

    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
