#include "Radiolist.h"

void Radiolist::selectOption() {

	if (selectedPosition == logicalPosition || selectedPosition + 1) {
		_options[selectedPosition].replace(1, 1, " ");
		_graphics.moveTo(panelLeft + _left + 2, panelTop + _top + logicalPosition + 1);
	}
	if (selectedPosition != logicalPosition) {
		selectedPosition = logicalPosition;
		_options[selectedPosition].replace(1, 1, "X");
	}
	else {
		selectedPosition = -1;
	}
}

