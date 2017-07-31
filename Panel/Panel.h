#pragma once
#include "../Common/Control.h"
#include <vector>
class Panel : public Control
{
	vector<Control*> controlArray;

public:
	Panel() :Control(0, 0) {}
	Panel(int height, int width) :Control(width, height) {}
	~Panel() {}
	//Add a Control element to the panel 
	void AddControl(Control &control, int left, int top) {
		control.setLeft(left);
		control.setTop(top);
		controlArray.push_back(&control);
	}
	void draw(Graphics graphics, int left, int top, int layer);
	void getAllControls(vector<Control*> *controls);
	void keyDown(WORD code, CHAR chr) {};
	void mousePressed(int x, int y, bool ifFirstButton) {
		for (int i = 0; i < controlArray.size(); i++) {
			controlArray[i]->mousePressed(x, y, ifFirstButton);
		}
	};
	bool canGetFocus() { return false; }

};

