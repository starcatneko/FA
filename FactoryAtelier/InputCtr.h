#pragma once

#include <memory>
#include "VECTOR2.h"
#include <map>

#define INPUT_CTL InputCtr::GetInstance()

enum touch_type
{
	NUETRAL,		// ニュートラル状態
	TOUCH,			// NEUTRAL時に押下
	PRESS,			// ボタン押下継続中
	RELEASE,		// ボタンが離される
	TOUCH_TYPE
};



class InputCtr
{
public:
	// 0b0001 
	static InputCtr &GetInstance()
	{
		return *s_Instance;
	}; 

	VECTOR2 GetPos();
	//MOUSE::Button();
	int MouseButton(int ButtonType);

	bool HitRange(VECTOR2 pos, VECTOR2 size);

	int KeyButton(int ButtonType);

	// 対応したボタンのカウンター処理
	//int Mouse

	void Update();
	bool Check(touch_type type);
private:
	struct MouseCtrDeleter
	{
		void operator ()(InputCtr* pt) const
		{
			delete pt;
		}
	};
	static std::unique_ptr<InputCtr, MouseCtrDeleter> s_Instance;
	InputCtr();
	~InputCtr();

	VECTOR2 pos;

	//short int pressCnt[BUTTON_TYPE];

	// マウス・キーボード入力情報
	std::map<int, int> pressCnt;
};

