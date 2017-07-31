#pragma once
#include "../Common/Control.h"
/*
* This is a class of "one line" Texbox
* Abilities:
* 1. Navigate with mose
* 2. Navigate with keybard
* 3. Delete and change text
* Length of entering text is restricted by length of Texbox
*/
class TextBox : public Control {
	int _cursorPosition;
	int _panelLeft;
	int _panelTop;
	string _value;
	Graphics _graphics;
public:
	TextBox(int width);
	void draw(Graphics graphics, int left, int top, int layer);
	void keyDown(WORD keyCode, CHAR character);
	void mousePressed(int x, int y, bool isLeft = true);
	bool canGetFocus();
	string GetValue();
	void SetValue(string value);
	void nowInFocus();
	~TextBox();
};