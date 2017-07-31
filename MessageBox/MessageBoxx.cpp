#include "MessageBoxx.h"

MessageBoxx::~MessageBoxx()
{
}

void MessageBoxx::draw(Graphics graphics, int left, int top, int layer) {
	graphics.setBackground((Color)GetBackground());
	graphics.setForeground((Color)GetForeground());
	//only prints the element When no one has pressed the buttons yet.
	if ((cancell.show == true) && (ok.show == true)) {
		Panel::draw(graphics, left, top, layer); //drawing the element to the screen (frame+buttons)
		graphics.write(left + 1, top + 1, _title); //draw the msgBox title and text
		graphics.write(left + 1, top + 2, _text);
	}
	//if the pressed buttons is in "press" mode.
	else if (cancell.show == true) {
		graphics.write(left + 1, top + 1, "You clicked: OK");
	}
	else if (ok.show == true) {
		graphics.write(left + 1, top + 1, "You clicked: Cancell ");
	}
}

void MessageBoxx::mousePressed(int x, int y, bool ifFirstButton) {
	Panel::mousePressed(x, y, ifFirstButton);
}



