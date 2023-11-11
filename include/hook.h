#pragma once

#include <windows.h>

// ac_client.exe + 17E254
// ac_client.exe + 17E360
// ac_client.exe + 18AC00
// ac_client.exe + 195404

struct Hook
{
	Hook() = default;
	
	void init();
};