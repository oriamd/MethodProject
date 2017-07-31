
#include <string>
#include "../Common/EventEngine.h"
#include "../TextBox/TextBox.h"
#include"../Label/Label.h"
#include"../Panel/Panel.h"
#include "../Checklist/Checklist.h"
#include "../Radiolist/Radiolist.h"
#include "../Button/Button.h"
#include "../ComboBox/ComboBox.h"
#include "../Common/MouseListener.h"
#include "../Common/Graphics.h"
#include"../MessageBox/MessageBoxx.h"
#include"../NumericBox/NumericBox.h"
#include <string>


using namespace std;

struct MyListener : public MouseListener
{
	MyListener(Control &c) : _c(c) { }
	void MousePressed(int x, int y, bool isLeft)
	{
		_c.SetBorder(BorderSolid());
	}
private:
	Control &_c;
};
int main(int argc, char **argv)
{
	BorderSolid myBorder;

	Panel main(40, 70); //panel(height,width)
	main.SetBorder(BorderSolid()); //for testing

	Label lCountry(15);
	lCountry.SetValue("Country : ");
	lCountry.SetForeground(ForegroundColor::Black);
	lCountry.SetBackground(BackgroundColor::Green);
	main.AddControl(lCountry, 1, 1);

	ComboBox cCountry(18, { "Israel", "italy", "Germany" });
	cCountry.SetSelectedIndex(1);
	cCountry.SetBorder(BorderSolid());
	cCountry.SetForeground(ForegroundColor::Blue);
	cCountry.SetBackground(BackgroundColor::Red);
	main.AddControl(cCountry, 1, 4);

	TextBox tAddress(30);
	tAddress.SetValue("Home Address");
	myBorder.setColor(Color::Blue);
	tAddress.SetForeground(ForegroundColor::White);
	tAddress.SetBackground(BackgroundColor::Purple);
	tAddress.SetBorder(myBorder);
	main.AddControl(tAddress, 28, 1);

	MessageBoxx msgBox(25, 8);
	msgBox.SetTitle("msgBox TITLE:");
	msgBox.SetText("this is my msgBox");
	msgBox.SetBorder(BorderSolid());
	msgBox.SetForeground(ForegroundColor::Orange);
	msgBox.SetBackground(BackgroundColor::Blue);
	main.AddControl(msgBox, 28, 10);

	Label lAge(10);
	lAge.SetValue("Age : ");
	lAge.SetForeground(ForegroundColor::Black);
	lAge.SetBackground(BackgroundColor::Green);
	main.AddControl(lAge, 1, 23);

	NumericBox numBox(11, 0, 20);
	numBox.SetValue(10);
	myBorder.setColor(Color::Purple);
	numBox.SetBorder(myBorder);
	numBox.SetForeground(ForegroundColor::Black);
	numBox.SetBackground(BackgroundColor::White);
	main.AddControl(numBox, 1, 26);

	Label lGender(12);
	lGender.SetValue("Gender : ");
	lGender.SetForeground(ForegroundColor::Black);
	lGender.SetBackground(BackgroundColor::Green);
	main.AddControl(lGender, 15, 23);

	Radiolist rSex(5, 15, { "Male", "Female" });
	rSex.SetBorder(BorderSolid());
	rSex.SetForeground(ForegroundColor::White);
	rSex.SetBackground(BackgroundColor::Red);
	main.AddControl(rSex, 7, 14);

	Label lHobbies(12);
	lHobbies.SetValue("Hobbies : ");
	lHobbies.SetForeground(ForegroundColor::Black);
	lHobbies.SetBackground(BackgroundColor::Green);
	main.AddControl(lHobbies, 40, 23);

	Checklist clhobbies(6, 15, { "Hike", "Books", "Movies", "Games" });
	clhobbies.SelectIndex(1);
	clhobbies.SetBorder(BorderSolid());
	clhobbies.SetForeground(ForegroundColor::Green);
	main.AddControl(clhobbies, 20, 13);



	Control::setFocus(cCountry);
	EventEngine engine;
	engine.run(main);
	return 0;
}