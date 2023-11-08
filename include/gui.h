#pragma once

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"	
#include <SDL.h>

namespace gui 
{	
	constexpr int GUI_WIDTH = 600;
	constexpr int GUI_HEIGHT = 400;


	void init() noexcept;
}