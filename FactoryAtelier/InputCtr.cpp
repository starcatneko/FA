#include "MouseCtr.h"
#include "DxLib.h"

std::unique_ptr<MouseCtr, MouseCtr::MouseCtrDeleter> MouseCtr::s_Instance(new MouseCtr());

MouseCtr::MouseCtr()
{
	
}

MouseCtr::~MouseCtr()
{
}

VECTOR2 MouseCtr::GetPos()
{
	return this->pos;
}

bool MouseCtr::HitRange(VECTOR2 pos, VECTOR2 size)
{
	VECTOR2 p = this->pos;
	if (p > pos&&
		p < pos + size
		&& pressCnt[LEFT] == 1)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 88);
		DrawBox(pos.x, pos.y, pos.x + size.x,
			pos.y + size.y, 0xDD0000, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


		return true;
	}
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_ADD, 88);
		DrawBox(pos.x, pos.y, pos.x + size.x,
			pos.y + size.y, 0x00DD00, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	}

	return false;
}



void MouseCtr::Update()
{
	/*
	short int temp_pressCnt = 0;
	switch (GetMouseInput())
	{
	case MOUSE_INPUT_LEFT:
		pressCnt[LEFT]++;
		break;
	case MOUSE_INPUT_RIGHT:
		pressCnt[RIGHT]++;
		break;
	case MOUSE_INPUT_MIDDLE:
		pressCnt[MIDDLE]++;

		break;
	}
	*/
	if (GetMouseInput() == MOUSE_INPUT_LEFT)
	{
		pressCnt[LEFT]++;
	}
	else if(pressCnt[LEFT] > 0)
	{
		pressCnt[LEFT] = -1;
	}
	else
	{
		pressCnt[LEFT] = 0;

	}


	for (auto itr : pressCnt)
	{
		//if (itr
			//pressCnt[itr];
	}

	GetMousePoint(&this->pos.x, &this->pos.y);


	return ;
}

bool MouseCtr::Check(touch_type type)
{
	return false;
}
