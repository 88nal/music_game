#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <graphics.h>
#include "allClass.h"
using namespace std;

void BlueKeys::show()
{
	setfillcolor(RGB(64, 149, 214));
	setlinecolor(WHITE);
	fillrectangle(mx - w, my, mx, my + h);
}

// void Sence::open()
//{
//	cout << 2 << endl;
//}