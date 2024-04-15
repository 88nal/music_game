#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <graphics.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"WINMM.LIB")
using namespace std;

void CenterText(int x, int y, int w, int h, const wchar_t* text);
//CenterText
//将文字显示在指定区域的中心

bool inArea(int mx, int my, int x, int y, int w, int h);
//inArea
//判断坐标是否位于指定区域之内

bool putButton(int x, int y, int w, int h, const wchar_t* text, int mx, int my, int msg_message, int r, int g, int b);
//putButton
//新建一个按钮在（x，y），宽度为w，高度为h，按钮内文字为text，鼠标点击位置（mx，my），msg_message为msg.message，rgb为颜色值

void playMusic();
