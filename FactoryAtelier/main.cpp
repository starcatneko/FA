#include "DxLib.h"
#include "GameTask.h"

//debug debugctr;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{


	GameTask::GetInstance().SystemInit();
	GameTask::GetInstance().Run();

	return 0;
}