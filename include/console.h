#pragma once


#include <windows.h>
#include <iostream>
#include <iomanip>


struct Console 
{
	void init();
	void exit();
	void printInfo();

	FILE* m_dummy;
	bool isAttached = false;
};
	
