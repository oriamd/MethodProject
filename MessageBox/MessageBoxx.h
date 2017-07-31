#pragma once
#include "../Common/Control.h"
#include "../Button/Button.h"
#include "../Panel/Panel.h"
#include "../Common/Graphics.h"

class OnClickOk : public MouseListener
{
public:
	bool show = true;
	OnClickOk() { }
	void MousePressed(int x, int y, bool isLeft)
	{
		if (show) {
			show = false;
		}
	}
private:
};

class OnClickCancel : public MouseListener
{
public:
	bool show = true;
	void MousePressed(int x, int y, bool isLeft) {
		if (show) {
			show = false;
		}
	}
private:
};


class MessageBoxx :public Panel
{

private:
	string _title;
	string _text;
	OnClickOk ok; //ok and cancell listeners for the buttons
	OnClickCancel cancell;
protected:
	Button _ok, _cancelled;
public:
	MessageBoxx(int height, int width) :Panel(width, height), _ok(4), _cancelled(9) {
		setZIndex(3);
		//adding the ok button
		_ok.setZIndex(4);
		_ok.SetValue("OK");
		_ok.SetBorder(BorderSolid());
		_ok.AddListener(ok);
		Panel::AddControl(_ok, getLeft(), getTop() + 1);

		//adding the cancelled button
		_cancelled.SetValue("Cancell");
		_cancelled.setZIndex(4);
		_cancelled.SetBorder(BorderSolid());
		_cancelled.AddListener(cancell);
		Panel::AddControl(_cancelled, getLeft() + 3, getTop() + 1);
	}
	void draw(Graphics graphics, int left, int top, int layer);
	void SetText(string text) { _text = text; }
	void SetTitle(string title) { _title = title; }

	void keyDown(WORD code, CHAR chr) {};
	void mousePressed(int x, int y, bool ifFirstButton);
	bool canGetFocus() { return false; }
	~MessageBoxx();
};

