#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <graphics.h>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"WINMM.LIB")

#include "allClass.h"
//#include "data.h"
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


bool put_image_Button(int x, int y, int w, int h, IMAGE buttons[], int mx, int my, int msg_message, int index);
//put_image_Button
//新建一个按钮在（x，y），宽度为w，高度为h，按钮内图片为buttons[index]，buttons[index+1]为鼠标移到按钮上后按钮颜色变深的效果，鼠标点击位置（mx，my），msg_message为msg.message


void playMusic(wchar_t pass_music[3][100], int music_index);
//playMusic
//播放pass_music[index]地址的音乐


void hitDetermine(BlueKeys& BK, int* type_text, int* num_text, ExMessage& msg);
//hitDetermine
//对BK对象的击打进行判断，type_text确定levelTextPut输出何种等级，num_text关于levelTextPut中各种字符串在屏幕上的保持时间


void levelTextPut(int* type_text_up, int* type_text_down, int* num_text_up, int* num_text_down);
//levelTextPut
//根据type_text_up，type_text_down判断在上下轨道输出什么等级文字，num_text_up，num_text_down关于等级文字的保持时间

void readDataFile(int music_index, vector<BlueKeys>& vec_BK);