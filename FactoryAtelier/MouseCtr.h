#pragma once

#include <memory>
#include "VECTOR2.h"
#define MOUSE MouseCtr::GetInstance()
enum touch_type
{
	NUETRAL,
	TOUCH,
	PRESS,
	RELEASE,
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
	// 0b0001 
	static MouseCtr &GetInstance()
	{
		return *s_Instance;
	};

	VECTOR2 GetPos();

	bool HitRange(VECTOR2 pos, VECTOR2 size);

	void Update();
	bool Check(touch_type type);
private:
	struct MouseCtrDeleter
	{
		void operator ()(MouseCtr* pt) const
		{
			delete pt;
		}
	};
	static std::unique_ptr<MouseCtr, MouseCtrDeleter> s_Instance;

	MouseCtr();
	~MouseCtr();

	VECTOR2 pos;

	short int pressCnt[BUTTON_TYPE];
};

