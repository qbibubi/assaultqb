#include "../include/gui.h"

void gui::create() noexcept 
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
}


void gui::init(SDL_Window* glWindow, void* glContext) noexcept
{
	ImGui_ImplSDL2_InitForOpenGL(glWindow, glContext);
	ImGui_ImplOpenGL3_Init();
}

void gui::render() noexcept 
{

}

void gui::shutdown() noexcept
{

}