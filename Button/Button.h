#pragma once
#include <vector>
#include "../Common/MouseListener.h"
#include "../Label/Label.h"

class Button : public Label {
	vector<MouseListener*> listeners;
	int panelLeft;
	int panelTop;
public:
	Button(int width) :Label(width, ""), panelLeft(0), panelTop(0) {}
	void draw(Graphics g, int left, int top, int layer);
	bool canGetFocus() { return false; }
	void AddListener(MouseListener &listener) { listeners.push_back(&listener); }
	void mousePressed(int x, int y, bool isLeft);
	~Button() {}
};

