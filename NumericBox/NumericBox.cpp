#include "NumericBox.h"


NumericBox::~NumericBox()
{
}

void NumericBox::SetValue(int val) {
	if (val <= _maxVal && val >= _minVal) {
		_val = val;
		minus.currentNum = _val;
		plus.currentNum = _val;
	}
}


void NumericBox::draw(Graphics graphics, int left, int top, int layer) {

	int realVal = GetValue();
	if (minus.needToReduce) {
		minus.currentNum--;
		SetValue(minus.currentNum);
		minus.needToReduce = false;
	}
	if (plus.needToAdd) {
		plus.currentNum++;
		SetValue(plus.currentNum);
		plus.needToAdd = false;
	}
	graphics.setBackground((Color)GetBackground());
	graphics.setForeground((Color)GetForeground());
	graphics.write(left + 1, top + 1, to_string(realVal));
	Panel::draw(graphics, left, top, layer);
}

void NumericBox::mousePressed(int x, int y, bool ifFirstButton) {
	Panel::mousePressed(x, y, ifFirstButton);
}