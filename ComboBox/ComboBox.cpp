#include "ComboBox.h"


void ComboBox::mousePressed(int x, int y, bool ifFirstButton) {
	Panel::mousePressed(x, y, ifFirstButton);
}

void ComboBox::draw(Graphics graphics, int left, int top, int layer) {
	if (layer != getZIndex()) {
		return;
	}
	Panel::draw(graphics, left, top, layer);
}
