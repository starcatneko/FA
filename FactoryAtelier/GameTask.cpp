#include "DxLib.h"
#include "GameTask.h"

#define SCREEN_SIZE_X 960
#define SCREEN_SIZE_Y 640


std::unique_ptr<GameTask, GameTask::GameTaskDeleter> GameTask::s_Instance(new GameTask());

GameTask::GameTask()
{
	CurrentScene = &GameTask::GameMain;
}


GameTask::~GameTask()
{

}

void GameTask::GameMain()
{
}

void GameTask::Run()
{
	LoadCSV("csv/test.csv",maphit);
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == false)
	{

		ScreenFlip();
		ClsDrawScreen();

		(this->*CurrentScene)();
	}

}

void GameTask::SystemInit()
{
	SetWindowText("window title");

	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
}

bool GameTask::LoadCSV(std::string filename, std::vector<VEC2_2> data)
{
	//�t�@�C�����X�g���[���ɓǂݍ���
	std::ifstream filestream(filename);
	if (!filestream)
	{
		return false;
	}
	std::string line;
	std::string tmp;
	int cell;
	// �s�P�ʓǂݍ���


	// �Z���ԍ��p
	while (std::getline(filestream, line))
	{
		int i = 0;
		// �x�N�g���ǉ�
		data.push_back({ { -0xffff, -0xffff },{ -0xffff, -0xffff } });
		std::istringstream linestream(line);
		if (!linestream)
		{
			return false;
		}
		// �Z���P�ʓǂݍ���
		while (std::getline(linestream, tmp, ','))
		{
			// �ǂݍ��񂾃Z���𕶎��񂩂琔�l�ɕϊ�����
			cell = atoi(tmp.c_str());

			if (i < 2)
				(data.back().vecA[i]) = cell;

			else
				(data.back().vecB[i - 2]) = cell;


			i++;
		}
		// ����̗v�f���ɖ����Ȃ��ꍇ�̃G���[����
		if (i < 4)
		{
			return false;
		}
	};
	return true;
	//data.push_back();
}
bool GameTask::LoadCSV(std::string filename, std::vector<VECTOR2> data)
{
	//�t�@�C�����X�g���[���ɓǂݍ���
	std::ifstream filestream(filename);
	if (!filestream)
	{
		return false;
	}
	std::string line;
	std::string tmp;
	int cell;
	// �s�P�ʓǂݍ���


	// �Z���ԍ��p
	while (std::getline(filestream, line))
	{
		int i = 0;
		// �x�N�g���ǉ�
		data.push_back({ -0xffff, -0xffff });
		std::istringstream linestream(line);
		if (!linestream)
		{
			return false;
		}
		// �Z���P�ʓǂݍ���
		while (std::getline(linestream, tmp, ','))
		{
			// �ǂݍ��񂾃Z���𕶎��񂩂琔�l�ɕϊ�����
			cell = atoi(tmp.c_str());
			(data.back()[i]) = cell;
			i++;
		}
		// ����̗v�f���ɖ����Ȃ��ꍇ�̃G���[����
		if (i < 2)
		{
			return false;
		}
	};
	return true;
	//data.push_back();
}
