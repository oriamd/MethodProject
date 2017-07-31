#include "Button.h"

void Button::mousePressed(int x, int y, bool isLeft) {
	if (isInside(x, y, _left + panelLeft, _top + panelTop, _width, _height)) {
		for (MouseListener* listener : listeners) {
			listener->MousePressed(x, y, isLeft);
		}
	}
}

void Button::draw(Graphics g, int left, int top, int layer) {
	if (layer == getZIndex()) {
		Label::draw(g, _left + (panelLeft = left), _top + (panelTop = top), layer);
		g.setCursorVisibility(false);
	}
}