#include "Label.h"

void Label::draw(Graphics graphics, int left, int top, int layer) {
	if (layer == getZIndex()) {
		Control::draw(graphics, left, top, layer);
		graphics.setBackground((Color)GetBackground());
		graphics.setForeground((Color)GetForeground());
		graphics.write(left + 1, top + 1, _value);
	}

}
