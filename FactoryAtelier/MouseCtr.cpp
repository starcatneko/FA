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
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 88);
	DrawBox(pos.x, pos.y,
		pos.x + size.x,
		pos.y + size.y,
		0x00DD00, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	if (p > pos&&
		p < pos + size)
	{
		return true;
	}
	return false;
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

	VECTOR2 v;
	GetMousePoint(&v.x, &v.y);
	this->pos = v;


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
