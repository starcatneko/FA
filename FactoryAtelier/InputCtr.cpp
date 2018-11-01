#include "InputCtr.h"
#include "DxLib.h"

std::unique_ptr<InputCtr, InputCtr::MouseCtrDeleter> InputCtr::s_Instance(new InputCtr());

InputCtr::InputCtr()
{
	
}

InputCtr::~InputCtr()
{
}

VECTOR2 InputCtr::GetPos()
{
	return this->pos;
}

bool InputCtr::HitRange(VECTOR2 pos, VECTOR2 size)
{



	VECTOR2 p = this->pos;
	if (p > pos&&
		p < pos + size
		&& pressCnt[MOUSE_INPUT_LEFT] == 1)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 88);
		DrawBox(pos.x, pos.y, pos.x + size.x,
			pos.y + size.y, 0xDD0000, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


		return true;
	}
	else if (p > pos&&
		p < pos + size
		&& pressCnt[MOUSE_INPUT_RIGHT] == 1)
	{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 88);
	DrawBox(pos.x, pos.y, pos.x + size.x,
		pos.y + size.y, 0x0000DD, true);
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

int InputCtr::KeyButton(int ButtonType)
{
	DrawFormatString(ButtonType>>8*10, ButtonType *10,
		0xffffff, "%d", pressCnt[ButtonType << 16]);

	if (CheckHitKey(ButtonType) == 1)
	{
		{
			pressCnt[ButtonType<<16]++;
		}
	}
	else if (pressCnt[ButtonType << 16] > 0)
	{
		pressCnt[ButtonType << 16] = -1;
	}
	else
	{
		pressCnt[ButtonType << 16] = 0;

	}
	return pressCnt[ButtonType << 16];


}


int InputCtr::MouseButton(int ButtonType)
{
	DrawFormatString(480, ButtonType * 32,
		0xffffff, "%d", pressCnt[ButtonType]);

	if (GetMouseInput() & ButtonType)
	{
		pressCnt[ButtonType]++;
	}
	else if (pressCnt[ButtonType] > 0)
	{
		pressCnt[ButtonType] = -1;
	}
	else
	{
		pressCnt[ButtonType] = 0;

	}
	return pressCnt[ButtonType];
}

void InputCtr::Update()
{
	
	/*
	for (auto itr : pressCnt)
	{
		//if (itr
			//pressCnt[itr];
	}
	*/
	GetMousePoint(&this->pos.x, &this->pos.y);


	return ;
}

bool InputCtr::Check(touch_type type)
{
	return false;
}
