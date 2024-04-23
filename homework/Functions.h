#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <fstream>
#include <graphics.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"WINMM.LIB")

#include "allClass.h"
using namespace std;

#define SPEED 3
#define WINDOWS_WIDE	1200
#define WINDOWS_HEIGHT	800

void CenterText(int x, int y, int w, int h, const char* text);
//CenterText
//��������ʾ��ָ�����������


bool inArea(int mx, int my, int x, int y, int w, int h);
//inArea
//�ж������Ƿ�λ��ָ������֮��


bool putButton(int x, int y, int w, int h, const char* text, int mx, int my, int msg_message, int r, int g, int b);
//putButton
//�½�һ����ť�ڣ�x��y�������Ϊw���߶�Ϊh����ť������Ϊtext�������λ�ã�mx��my����msg_messageΪmsg.message��rgbΪ��ɫֵ


bool put_image_Button(int x, int y, int w, int h, IMAGE buttons[], int mx, int my, int msg_message, int index);
//put_image_Button
//�½�һ����ť�ڣ�x��y�������Ϊw���߶�Ϊh����ť��ͼƬΪbuttons[index]��buttons[index+1]Ϊ����Ƶ���ť�Ϻ�ť��ɫ�����Ч���������λ�ã�mx��my����msg_messageΪmsg.message
bool put_image_Button(int x, int y, int w, int h, IMAGE buttons[], int mx, int my, int msg_message, int index, int des);
//put_image_Button�����أ��������ΰ������ж�����
//�½�һ����ť�ڣ�x��y�������Ϊw���߶�Ϊh����ť��ͼƬΪbuttons[index]��buttons[index+1]Ϊ����Ƶ���ť�Ϻ�ť��ɫ�����Ч���������λ�ã�mx��my����msg_messageΪmsg.message


void playMusic(char pass_music[][100], int music_index);
//playMusic
//����pass_music[index]��ַ������


void hitDetermine(BlueKeys& BK, int* type_text, int* num_text, ExMessage& msg);
//hitDetermine
//��BK����Ļ�������жϣ�type_textȷ��levelTextPut������ֵȼ���num_text����levelTextPut�и����ַ�������Ļ�ϵı���ʱ��



void levelTextPut(int* type_text, int* num_text, int temp);
//levelTextPut
//����type_text�ж������¹�����ʲô�ȼ����֣�num_text���ڵȼ����ֵı���ʱ��, temp�������λ�ã�0Ϊ�Ϲ����1Ϊ�¹��


void readDataFile(int music_index, vector<BlueKeys>& vec_BK, char pass_musicData[][100]);
//readDataFile
//��ȡ��Ӧ���ֵ����棬���������vector������