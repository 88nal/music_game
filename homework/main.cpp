#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include "Functions.h"


void PutChoiseWindow(char all_music[4][50]);

bool PutBeginWindow(IMAGE buttons[]);

void load_game_resources();

void img_FadeAway(IMAGE m_img)
{
	while (1)
	{
		DWORD* buffer = GetImageBuffer(&m_img);
		BYTE r;
		BYTE g;
		BYTE b;
		int width = m_img.getwidth();
		int height = m_img.getheight();
		double RATIO = 0.99;
		int t = clock();
		while (1)
		{
			int t_ = clock();

			for (int i = 0; i < width * height; i++)
			{
				DWORD pixel = buffer[i];

				r = (BYTE)(GetBValue(pixel) * RATIO + GetBValue(BLACK) * (1 - RATIO));
				g = (BYTE)(GetGValue(pixel) * RATIO + GetGValue(BLACK) * (1 - RATIO));
				b = (BYTE)(GetRValue(pixel) * RATIO + GetRValue(BLACK) * (1 - RATIO));

				buffer[i] = BGR(RGB(r, g, b));

			}

			putimage(0, 0, &m_img);
			FlushBatchDraw();

			if (t_ - t >= 2500) { return; }
		}
	}
}

ExMessage msg = { 0 };

IMAGE buttons_BeginWindow[4];
IMAGE img_welcome;

char all_music[4][50] =
{
	"Eutopia",
	"InterstellarJourney",
	"MistyMemory",
	"39music"
};

char pass_music[4][100] =
{
	"open music\\Eutopia.mp3 alias bkmusic",
	"open music\\InterstellarJourney.mp3 alias bkmusic",
	"open music\\MistyMemory.mp3 alias bkmusic",
	"open music\\39music.mp3 alias bkmusic"
};

char pass_musicData[4][100] =
{
	"data\\data_Eutopia.txt",
	"data\\data_InterstellarJourney.txt",
	"data\\data_MistyMemory_add.txt",
	"data\\data_39music_add.txt"
};

int windows = 0;	
int windows_music = 0;	
int music_index = -1;
char now[100];

bool testmode = false;

int main()
{
	load_game_resources();

	initgraph(WINDOWS_WIDE, WINDOWS_HEIGHT, EX_DBLCLKS);
	setbkcolor(BLACK);
	cleardevice();

	
	const clock_t FPS = 1000 / 80;
	int FPS_starttime = 0;
	int FPS_endtime = 0;

	int type_text_up = -1;
	int type_text_down = -1;
	int num_text_up = 0;
	int num_text_down = 0;

	bool time_delay_bool = true;
	int time_delay = 0;
	
	while (1)
	{
		//img_FadeAway(img_welcome);

		while (windows == 0)
		{
			if (PutBeginWindow(buttons_BeginWindow))
			{
				return 0;
			}
		}

		while (windows == 1)
		{
			PutChoiseWindow(all_music);
			
		}

		
		vector<BlueKeys> vec_BK;				
		readDataFile(music_index, vec_BK, pass_musicData);			//读取对应音乐的谱面文件
		

		if (windows_music == 1)
		{
			playMusic(pass_music, music_index);			//播放对应音乐
			while (1)
			{
				cleardevice();
				
				for (int i = 0; i < vec_BK.size(); i++)
				{
					if (vec_BK[i].value_put == true)
					{
						vec_BK[i].mx -= SPEED;			//移动速度
					}
				}

				FPS_starttime = clock();			//帧率开始计算的时间

				mciSendString("status bkmusic position", now, 100, 0);
				//cout << now << endl;
				int HKS = atoi(now) + 4300;					//音乐开始播放的初始时间
				//cout << HKS << endl;

				//if (time_delay_bool)
				//{
				//	time_delay = FPS_starttime;
				//	time_delay_bool = false;		//time_delay_bool仅赋值一次
				//}

				//HKS -= time_delay;					//使音乐开始使的计时为0，即记录的时间与音乐播放的时间相同

				

				//cout << HKS << endl;

				if (peekmessage(&msg, EX_MOUSE | EX_KEY))
				{

				}

				BeginBatchDraw();
				cleardevice();

				line(200, 0, 200, 800);				//判定线

				for (int i = 0; i < vec_BK.size(); i++)
				{
					if (vec_BK[i].mtime - HKS <= 10 && vec_BK[i].value_put == false)	//键本身的mtime与HKS对比，小于10ms，value_put由false变为true，即允许绘制
					{
						vec_BK[i].value_put = true;
					}

					if (vec_BK[i].value_put == true && vec_BK[i].value_hit == false)
					{
						vec_BK[i].show();

						if (msg.message == WM_KEYDOWN && vec_BK[i].my == 200)
						{
							switch (msg.vkcode)
							{
							case 0x44:	//D
								hitDetermine(vec_BK[i], &type_text_up, &num_text_up, msg);
							case 0x46:	//F
								hitDetermine(vec_BK[i], &type_text_up, &num_text_up, msg);
								break;
							}
						}
						else if (msg.message == WM_KEYDOWN && vec_BK[i].my == 400)
						{
							switch (msg.vkcode)
							{
							case 0x4A:	//J
								hitDetermine(vec_BK[i], &type_text_down, &num_text_down, msg);
								break;
							case 0x4B:	//K
								hitDetermine(vec_BK[i], &type_text_down, &num_text_down, msg);
								break;
							}
						}
						else if (msg.message == 0 && vec_BK[i].mx <= 10)
						{
							if (vec_BK[i].my == 200)	type_text_up = 0;
							else if (vec_BK[i].my == 400)	type_text_down = 0;
							
							vec_BK[i].value_hit = true;
						}
					}
				}

				setbkmode(TRANSPARENT);

				levelTextPut(&type_text_up, &num_text_up, 0);
				levelTextPut(&type_text_down, &num_text_down, 1);

				EndBatchDraw();

				msg.message = 0;

				FPS_endtime = clock();			//帧率结束计算的时间

				if (FPS_endtime - FPS_starttime < FPS)		
				{
					Sleep(FPS - FPS_endtime + FPS_starttime);	//保持每次循环60ms
				}
			}
		}
	}
	
	return 0;
}

bool PutBeginWindow(IMAGE buttons[])
{
	BeginBatchDraw();
	cleardevice();

	if (peekmessage(&msg, EX_MOUSE | EX_KEY))
	{

	}

	if (testmode == false)
	{
		if (putButton(1000, 600, 100, 30, "TestMode OFF", msg.x, msg.y, msg.message, 55, 55, 55))
		{
			testmode = true;
		}
	}
	else if (testmode == true)
	{
		if (putButton(1000, 600, 100, 30, "TestMode ON", msg.x, msg.y, msg.message, 55, 55, 55))
		{
			testmode = false;
		}
	}

	if (put_image_Button(300, 200, buttons[0].getwidth(), buttons[0].getheight(), buttons, msg.x, msg.y, msg.message, 0, 0))
	{
		cleardevice();
		Sleep(100);
		windows = 1;
	}

	/*if (put_image_Button(300, 300, buttons[2].getwidth(), buttons[2].getheight(), buttons, msg.x, msg.y, msg.message, 2))
	{
		return true;
	}*/

	EndBatchDraw();

	msg.message = 0;

	return false;
}

void PutChoiseWindow(char all_music[4][50])
{
	int y = 100;

	if (peekmessage(&msg, EX_MOUSE | EX_KEY))
	{

	}

	BeginBatchDraw();
	cleardevice();

	for (int i = 0; i < 4; i++)
	{
		if (putButton(500, y, 200, 80, all_music[i], msg.x, msg.y, msg.message, 230, 109, 2))
		{
			music_index = i;
			windows_music = 1;
			windows = 2;

			msg.message = 0;
		}
		
		
		y += 100;
	}
	
	msg.message = 0;

	EndBatchDraw();
}

void load_game_resources()
{
	loadimage(&buttons_BeginWindow[0], "buttons\\BEGIN.png", 400, 400);
	loadimage(&buttons_BeginWindow[1], "buttons\\BEGIN_t.png", 400, 400);
	loadimage(&buttons_BeginWindow[2], "buttons\\QUIT.png", 400, 150);
	loadimage(&buttons_BeginWindow[3], "buttons\\QUIT_t.png", 400, 150);

	loadimage(&img_welcome, "img\\img_welcome.jpg", 1200, 800);

	return;
}



