#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include <graphics.h>
#include <conio.h>
#include "Functions.h"
#include "allClass.h"
using namespace std;

ExMessage msg = { 0 };

int windows = 0;	

int main()
{
	ifstream fin;
	vector<BlueKeys> vec_BK;
	//int fin_index = 0;
	BlueKeys bk_temp;

	fin.open("data\\test.txt");

	while (fin >> bk_temp.mx)
	{
		fin >> bk_temp.my;
		fin >> bk_temp.mtime;

		vec_BK.push_back(bk_temp);
	}

	for (int i = 0; i < vec_BK.size(); i++)
	{
		cout << i << ":" << vec_BK[i].mx << endl;;
	}

	fin.close();

	initgraph(1200, 800, EX_DBLCLKS);
	setbkcolor(BLACK);
	cleardevice();

	playMusic();
	
	const clock_t FPS = 1000 / 80;
	int FPS_starttime = 0;
	int FPS_endtime = 0;

	while (1)
	{
		FPS_starttime = clock();
		
		for (int i = 0; i < vec_BK.size(); i++)
		{
			vec_BK[i].mx -= 2;
		}

		if (peekmessage(&msg, EX_MOUSE | EX_KEY))
		{

		}

		BeginBatchDraw();
		cleardevice();

		line(200, 0, 200, 800);
		//line(210, 0, 210, 800);
		//line(220, 0, 220, 800);

		for (int i = 0; i < vec_BK.size(); i++)
		{
			/*if (vec_BK[i].mx == vec_BK[i].w && vec_BK[i].value == false)
			{
				outtextxy(225, 225, L"Miss");
				cout << "Miss" << endl;
				vec_BK[i].value = true;
			}*/
			if (vec_BK[i].value == false)
			{
				vec_BK[i].show();

				if (msg.message == WM_KEYDOWN)
				{
					switch (msg.vkcode)
					{
					case 0x44:
						if (vec_BK[i].mx >= 190 && vec_BK[i].mx <= 210)
						{
							outtextxy(225, 225, L"Perfect");
							vec_BK[i].value = true;
						}
						else if ((vec_BK[i].mx > 180 && vec_BK[i].mx <= 190) || (vec_BK[i].mx > 210 && vec_BK[i].mx <= 220))
						{
							outtextxy(225, 225, L"Good");
							vec_BK[i].value = true;
						}
						else if ((vec_BK[i].mx > 160 && vec_BK[i].mx <= 180) || (vec_BK[i].mx > 230 && vec_BK[i].mx <= 250))
						{
							outtextxy(225, 225, L"Bad");
							vec_BK[i].value = true;
						}
						else
						{
							outtextxy(225, 225, L"Miss");
							vec_BK[i].value = true;
						}
						break;
					case 0x4A:
						//cout << "J" << endl;
						break;
					}
				}
				else if (msg.message == WM_KEYUP)
				{
					switch (msg.vkcode)
					{
					case 0x44:
						break;
					case 0x4A:
						break;
					}
				}
			}
			else
			{
				cout << i << ": true" << endl;
			}
		}

		

		EndBatchDraw();

		

		FPS_endtime = clock();

		if (FPS_endtime - FPS_starttime < FPS)
		{
			Sleep(FPS - FPS_endtime + FPS_starttime);
		}
	}

	return 0;
}

//int main()
//{
//	mciSendString(L"open music\\Eutopia.mp3 alias bkmusic", NULL, 0, NULL);
//	mciSendString(L"play bkmusic repeat", NULL, 0, NULL);
//
//	getchar();
//	return 0;
//}