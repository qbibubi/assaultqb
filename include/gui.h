#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl2.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_opengl3_loader.h"
#include <sdl/SDL.h>
#include <windows.h>

namespace gui 
{	
	ImVec2 windowSize( 600, 600 );

	void create() noexcept;
	void init(SDL_Window* glWindow, void* glContext) noexcept;
	void render() noexcept;
	void shutdown() noexcept;
}