#pragma once

enum touch_type
{
	NEW ,
	OLD ,
	TOUCH_TYPE
};
enum button_type
{
	LEFT,
	RIGHT,
	MIDDLE,
	BUTTON_TYPE
};
class MouseCtr
{
public:
	MouseCtr();
	~MouseCtr();
	// 0b0001 
	void Update();
	bool Check(int short checkflg);
private:
	short int flg[TOUCH_TYPE];
};

