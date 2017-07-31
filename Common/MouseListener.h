#pragma once

#include "../Button/Button.h"

class MouseListener
{
public:
	virtual void MousePressed(int x, int y, bool isLeft) = 0;
};