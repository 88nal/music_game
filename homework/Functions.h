#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <graphics.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"WINMM.LIB")
using namespace std;

void CenterText(int x, int y, int w, int h, const wchar_t* text);
//CenterText
//��������ʾ��ָ�����������

bool inArea(int mx, int my, int x, int y, int w, int h);
//inArea
//�ж������Ƿ�λ��ָ������֮��

bool putButton(int x, int y, int w, int h, const wchar_t* text, int mx, int my, int msg_message, int r, int g, int b);
//putButton
//�½�һ����ť�ڣ�x��y�������Ϊw���߶�Ϊh����ť������Ϊtext�������λ�ã�mx��my����msg_messageΪmsg.message��rgbΪ��ɫֵ

void playMusic();
