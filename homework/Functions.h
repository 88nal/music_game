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
//��������ʾ��ָ�����������


bool inArea(int mx, int my, int x, int y, int w, int h);
//inArea
//�ж������Ƿ�λ��ָ������֮��


bool putButton(int x, int y, int w, int h, const wchar_t* text, int mx, int my, int msg_message, int r, int g, int b);
//putButton
//�½�һ����ť�ڣ�x��y�������Ϊw���߶�Ϊh����ť������Ϊtext�������λ�ã�mx��my����msg_messageΪmsg.message��rgbΪ��ɫֵ


bool put_image_Button(int x, int y, int w, int h, IMAGE buttons[], int mx, int my, int msg_message, int index);
//put_image_Button
//�½�һ����ť�ڣ�x��y�������Ϊw���߶�Ϊh����ť��ͼƬΪbuttons[index]��buttons[index+1]Ϊ����Ƶ���ť�Ϻ�ť��ɫ�����Ч���������λ�ã�mx��my����msg_messageΪmsg.message


void playMusic(wchar_t pass_music[3][100], int music_index);
//playMusic
//����pass_music[index]��ַ������


void hitDetermine(BlueKeys& BK, int* type_text, int* num_text, ExMessage& msg);
//hitDetermine
//��BK����Ļ�������жϣ�type_textȷ��levelTextPut������ֵȼ���num_text����levelTextPut�и����ַ�������Ļ�ϵı���ʱ��


void levelTextPut(int* type_text_up, int* type_text_down, int* num_text_up, int* num_text_down);
//levelTextPut
//����type_text_up��type_text_down�ж������¹�����ʲô�ȼ����֣�num_text_up��num_text_down���ڵȼ����ֵı���ʱ��

void readDataFile(int music_index, vector<BlueKeys>& vec_BK);