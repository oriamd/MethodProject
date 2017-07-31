#include "Panel.h"


void Panel::draw(Graphics graphics, int left, int top, int layer) {
	Control::draw(graphics, left, top, layer);
	for (int i = 0; i < controlArray.size(); i++) {
		if (controlArray[i]->isVisible()) {
			controlArray[i]->draw(graphics, controlArray[i]->getLeft() + left + 1, controlArray[i]->getTop() + top + 1, layer);
		}
	}
}

void Panel::getAllControls(vector<Control*> *controls) {
	controls->push_back(this);
	for (auto c : controlArray) {
		c->getAllControls(controls);
	}
}

