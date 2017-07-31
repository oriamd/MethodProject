#pragma once
#include "../Button/Button.h"
#include "../Radiolist/Radiolist.h"
#include "../Panel/Panel.h"
struct DropdownButtonListener : public MouseListener {
	DropdownButtonListener(Radiolist &c, Button &b, vector<string> options) : _c(c), _b(b), _options(options) {}
	void MousePressed(int x, int y, bool isLeft) {
		if (_c.isVisible()) {
			int index = _c.GetSelectedIndex();
			if (index != -1) {
				_b.SetValue("|V|" + _options[index]);
			}
			_c.Hide();
		}
		else {
			_c.Show();
		}
	}
private:
	Radiolist &_c;
	Button &_b;
	vector<string> _options;
};


class ComboBox : public Panel {
	Button dropdown;
	Radiolist list;
	DropdownButtonListener listener;
public:
	ComboBox(int width, vector<string> options) :
		Panel(width, 25), dropdown(width), list(options.size() + 2, width, options), listener(list, dropdown, options)
	{
		dropdown.setZIndex(5);
		list.Hide();
		list.setZIndex(5);
		dropdown.SetValue("|V|" + options[0]);
		dropdown.AddListener(listener);
		dropdown.SetBorder(BorderSolid());
		list.SetBorder(BorderSolid());
		AddControl(dropdown, 0, 0);
		AddControl(list, 0, 1);
	}

	virtual void SetForeground(ForegroundColor color) {
		_foregroundColor = color;
		list.SetForeground(GetForeground());
		dropdown.SetForeground(GetForeground());
	}

	virtual void SetBackground(BackgroundColor color) {
		_backgroundColor = color;
		list.SetBackground(GetBackground());
		dropdown.SetBackground(GetBackground());
	}

	void SetSelectedIndex(size_t index) { list.SetSelecdetIndex(index); }
	size_t GetSelectedIndex() { return list.GetSelectedIndex(); }
	void mousePressed(int x, int y, bool ifFirstButton);
	void draw(Graphics graphics, int left, int top, int layer);
	bool canGetFocus() { return false; }
};