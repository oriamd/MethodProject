#include "TextBox.h"

TextBox::TextBox(int width)
	:Control(width, 3),
	_cursorPosition(0),
	_panelLeft(0),
	_panelTop(0),
	_value("") {
}

void TextBox::keyDown(WORD keyCode, CHAR character) {
	if (_value.size() < _width - 2) {//check if you can change the content in textbox
		if (character > '\x1F' && character < '\x7F') {//check if value is not a navigation key
			printf("%c", character);
			if (_value.size() == _cursorPosition - 1) {
				_value += character;
			}
			else {
				_value.insert(_cursorPosition, &character, 1);
			}
			Control::graphics.moveTo(_left + _value.size() + 1, _top + 1);
			++_cursorPosition;
			return;
		}
	}
	switch (keyCode) {
	case VK_RIGHT: {
		if (_cursorPosition < _width) {
			++_cursorPosition;
			Control::graphics.moveTo(_left - _value.size() - 1, _top + 2);
		}
		break;
	}
	case VK_LEFT: {
		if (_cursorPosition > 0) {
			--_cursorPosition;
			Control::graphics.moveTo(_left + _value.size() + 1, _top + 2);
		}
		break;
	}
	case VK_BACK: {
		if (_cursorPosition  > 0) {
			--_cursorPosition;
			_value.erase(_cursorPosition, 1);
		}
		break;
	}
	case VK_DELETE: {
		if (_cursorPosition > 0) {
			_value.erase(_cursorPosition, 1);
		}
		break;
	}
	}
}

void TextBox::mousePressed(int x, int y, bool isLeft) {
	if (isVisible()) {
		if (x - _left - 2 < _value.size() && y == _top + 2) {
			Control::setFocus(*this);
			_cursorPosition = x - _left - 1;
		}
	}
}

void  TextBox::draw(Graphics g, int left, int top, int layer) {
	if (layer == getZIndex()) {
		Control::draw(g, left, top, layer);
		g.setCursorVisibility(true);
		g.setBackground(static_cast<Color>(GetBackground()));
		g.setForeground(static_cast<Color>(GetForeground()));
		g.write(left + 1, top + 1, _value);
		g.moveTo(left + 1 + _value.size(), top + 1);
	}
}

bool TextBox::canGetFocus() { return true; }

string TextBox::GetValue() { return _value; }

void TextBox::SetValue(string value) { _cursorPosition = (_value = value).length(); }

void TextBox::nowInFocus() {
	Control::graphics.moveTo(_left + _cursorPosition + 2, _top + 2);
	_graphics.setCursorVisibility(true);
}

TextBox::~TextBox() {}