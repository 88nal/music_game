#define _CRT_SECURE_NO_WARNINGS 1
#include "loadResources.h"



void load_game_resources()
{
	IMAGE buttons[4];

	loadimage(&buttons[0], L"buttons\\BEGIN.png", 400, 150);
	loadimage(&buttons[1], L"buttons\\BEGIN_t.png", 400, 150);
	loadimage(&buttons[2], L"buttons\\QUIT.png", 400, 150);
	loadimage(&buttons[3], L"buttons\\QUIT_t.png", 400, 150);

	return;
}