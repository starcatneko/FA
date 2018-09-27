#pragma once

#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "VECTOR2.h"

//class MouseCtr;

typedef struct
{
	//マップの当たり判定ベクトル用
	VECTOR2 vecA;
	VECTOR2 vecB;		
}VEC2_2;

class GameTask
{
public:
	static GameTask &GetInstance()
	{
		return *s_Instance;
	};
	void Run();
	void SystemInit();

	// -----CSV読み込み

	// ベクトル格納用
	bool LoadCSV(std::string filename, std::vector <VEC2_2> data);
	bool LoadCSV(std::string filename, std::vector <VECTOR2> data);

private:
	struct GameTaskDeleter
	{
		void operator ()(GameTask* GameTask) const
		{
			delete GameTask;
		}
	};

	static std::unique_ptr<GameTask, GameTaskDeleter> s_Instance;
	//std::unique_ptr<MouseCtr> Mouse;
	GameTask();
	~GameTask();
	void (GameTask::*CurrentScene)();
	void GameMain();

	std::vector <VECTOR2> maphit;
};