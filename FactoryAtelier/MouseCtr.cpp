#include "MouseCtr.h"
#include "DxLib.h"

MouseCtr::MouseCtr()
{

}

MouseCtr::~MouseCtr()
{
}

void MouseCtr::Update()
{
	short int temp_flg = 0;
	flg[OLD] = flg[NEW];
	switch (GetMouseInput())
	{
	case MOUSE_INPUT_LEFT:
		if (flg[OLD] & 0b0001 && !(flg[NEW] & 0b0001))
		{
			temp_flg += 0b0001;
		}
		break;
	case MOUSE_INPUT_RIGHT:
		if (flg[OLD] & 0b0010 && !(flg[NEW] & 0b0010))
		{
			temp_flg += 0b0010;
		}
		break;
	case MOUSE_INPUT_MIDDLE:
		if (flg[OLD] & 0b0100 && !(flg[NEW] & 0b0100))
		{
			temp_flg += 0b0100;
		}
		break;
	}
	return ;
}

bool MouseCtr::Check(int short checkflg)
{
	if (flg[NEW] & checkflg && !(flg[NEW] & flg[OLD]))
	{
		return true;
	}
	return false;
}
