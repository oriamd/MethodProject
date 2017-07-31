#pragma once
#include "Control.h"
#include <Windows.h>
#include <vector>

#define READ_BUFFER_SIZE 128

class EventEngine
{
	Graphics _graphics;
	HANDLE _console;
	DWORD _consoleMode;
	virtual void moveFocus(Control &main, Control *focused);
public:
	EventEngine(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	virtual ~EventEngine();
	void run(Control &c);
};