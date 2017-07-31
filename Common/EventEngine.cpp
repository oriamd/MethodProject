#include "EventEngine.h"

EventEngine::EventEngine(DWORD input, DWORD output)
	: _console(GetStdHandle(input)), _graphics(output)
{
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

void EventEngine::run(Control &c)
{
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[READ_BUFFER_SIZE], record;
	HANDLE hStdin;//
	DWORD fdwSaveOldMode;//

						 // Get the standard input handle. 
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;

	// Save the current input mode, to be restored on exit. 
	GetConsoleMode(hStdin, &fdwSaveOldMode);

	// Enable the window and mouse input events. 
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	SetConsoleMode(hStdin, fdwMode);

	for (bool redraw = true;;)
	{
		if (redraw)
		{
			_graphics.clearScreen();
			_graphics.setCursorVisibility(false);
			for (size_t p = 0; p < 6; ++p)
				c.draw(_graphics, 0, 0, p);
			redraw = false;
			Control::getFocus()->nowInFocus();
		}

		ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			READ_BUFFER_SIZE,         // size of read buffer 
			&cNumRead); // number of records read 

		for (i = 0; i < cNumRead; i++) {
			record = irInBuf[i];
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT:
			{
				auto f = Control::getFocus();
				if ((f != nullptr) && (record.Event.KeyEvent.bKeyDown))
				{
					auto code = record.Event.KeyEvent.wVirtualKeyCode;
					auto chr = record.Event.KeyEvent.uChar.AsciiChar;
					if (code == VK_TAB)
						moveFocus(c, f);
					else {
						f->keyDown(code, chr);
					}
					redraw = true;
				}
				break;
			}
			case MOUSE_EVENT:
			{
				auto button = record.Event.MouseEvent.dwButtonState;
				auto coord = record.Event.MouseEvent.dwMousePosition;
				auto x = coord.X - c.getLeft();
				auto y = coord.Y - c.getTop();
				if (button == FROM_LEFT_1ST_BUTTON_PRESSED || button == RIGHTMOST_BUTTON_PRESSED)
				{
					c.mousePressed(x, y, button == FROM_LEFT_1ST_BUTTON_PRESSED);
					redraw = true;
				}
				break;
			}
			default:
				break;
			}
		}
	}
}

EventEngine::~EventEngine()
{
	SetConsoleMode(_console, _consoleMode);
}

void EventEngine::moveFocus(Control &main, Control *focused)
{
	vector<Control*> controls;
	main.getAllControls(&controls); //fill in recursive way the controls vector
	auto it = find(controls.begin(), controls.end(), focused);
	do {
		if (++it == controls.end()) {
			it = controls.begin();
		}
	} while (!(*it)->canGetFocus());
	Control::setFocus(**it);
}