#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include "Functions.h"

void PutChoiseWindow(wchar_t all_music[4][50]);

bool PutBeginWindow(IMAGE buttons[]);

ExMessage msg = { 0 };

wchar_t all_music[3][50] =
{
	L"Eutopia",
	L"InterstellarJourney",
	L"MistyMemory"
};

wchar_t pass_music[3][100] =
{
	L"open music\\Eutopia.mp3 alias bkmusic",
	L"open music\\InterstellarJourney.mp3 alias bkmusic",
	L"open music\\MistyMemory.mp3 alias bkmusic"
};

int windows = 0;	
int windows_music = 0;	
int music_index = -1;

int main()
{
	initgraph(1200, 800, EX_DBLCLKS);
	setbkcolor(BLACK);
	cleardevice();

	IMAGE buttons[4];

	loadimage(&buttons[0], L"buttons\\BEGIN.png", 400, 150);
	loadimage(&buttons[1], L"buttons\\BEGIN_t.png", 400, 150);
	loadimage(&buttons[2], L"buttons\\QUIT.png", 400, 150);
	loadimage(&buttons[3], L"buttons\\QUIT_t.png", 400, 150);
	
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
		
		while (windows == 0)
		{
			if (PutBeginWindow(buttons))
			{
				return 0;
			}
		}

		while (windows == 1)
		{
			PutChoiseWindow(all_music);
			
		}

		playMusic(pass_music, music_index);

		if (windows_music == 1)
		{
			vector<BlueKeys> vec_BK;
			readDataFile(music_index, vec_BK);

			while (1)
			{
				cleardevice();

				FPS_starttime = clock();

				int HKS = clock();

				if (time_delay_bool)
				{
					time_delay = FPS_starttime;
					time_delay_bool = false;
				}

				HKS -= time_delay;

				for (int i = 0; i < vec_BK.size(); i++)
				{
					if (vec_BK[i].value_put == true)
					{
						vec_BK[i].mx -= 3;
					}
				}

				//cout << HKS << endl;

				if (peekmessage(&msg, EX_MOUSE | EX_KEY))
				{

				}

				BeginBatchDraw();
				cleardevice();

				line(200, 0, 200, 800);

				

				for (int i = 0; i < vec_BK.size(); i++)
				{
					if (vec_BK[i].mtime - HKS <= 10 && vec_BK[i].value_put == false)
					{
						vec_BK[i].value_put = true;
						cout << HKS << endl;
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
								/*if (vec_BK[i].mx >= 190 && vec_BK[i].mx <= 210)
								{
									type_text_up = 3;
									vec_BK[i].value_hit = true;
									msg.message = 0;
								}
								else if ((vec_BK[i].mx > 180 && vec_BK[i].mx <= 190) || (vec_BK[i].mx > 210 && vec_BK[i].mx <= 220))
								{
									type_text_up = 2;
									vec_BK[i].value_hit = true;
									msg.message = 0;
								}
								else if ((vec_BK[i].mx > 160 && vec_BK[i].mx <= 180) || (vec_BK[i].mx > 230 && vec_BK[i].mx <= 250))
								{
									type_text_up = 1;
									vec_BK[i].value_hit = true;
									msg.message = 0;
								}
								else
								{
									type_text_up = 0;
									vec_BK[i].value_hit = true;
									msg.message = 0;
								}*/
								break;
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
								/*if (vec_BK[i].mx >= 190 && vec_BK[i].mx <= 210)
								{
									type_text_down = 3;
									vec_BK[i].value_hit = true;
									msg.message = 0;
								}
								else if ((vec_BK[i].mx > 180 && vec_BK[i].mx <= 190) || (vec_BK[i].mx > 210 && vec_BK[i].mx <= 220))
								{
									type_text_down = 2;
									vec_BK[i].value_hit = true;
									msg.message = 0;
								}
								else if ((vec_BK[i].mx > 160 && vec_BK[i].mx <= 180) || (vec_BK[i].mx > 230 && vec_BK[i].mx <= 250))
								{
									type_text_down = 1;
									vec_BK[i].value_hit = true;
									msg.message = 0;
								}
								else
								{
									type_text_down = 0;
									vec_BK[i].value_hit = true;
									msg.message = 0;
								}*/
								break;
							}
						}
						else if (msg.message == 0 && vec_BK[i].mx <= 10)
						{
							type_text_up = 0;
							vec_BK[i].value_hit = true;
						}
					}
				}

				setbkmode(TRANSPARENT);

				levelTextPut(&type_text_up, &type_text_down, &num_text_up, &num_text_down);

				EndBatchDraw();

				msg.message = 0;

				FPS_endtime = clock();

				if (FPS_endtime - FPS_starttime < FPS)
				{
					Sleep(FPS - FPS_endtime + FPS_starttime);
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

	if (put_image_Button(300, 100, buttons[0].getwidth(), buttons[0].getheight(), buttons, msg.x, msg.y, msg.message, 0))
	{
		cleardevice();
		Sleep(100);
		windows = 1;
	}

	if (put_image_Button(300, 300, buttons[2].getwidth(), buttons[2].getheight(), buttons, msg.x, msg.y, msg.message, 2))
	{
		return true;
	}

	EndBatchDraw();

	return false;
}

void PutChoiseWindow(wchar_t all_music[4][50])
{
	int y = 100;

	if (peekmessage(&msg, EX_MOUSE | EX_KEY))
	{

	}

	BeginBatchDraw();
	cleardevice();

	for (int i = 0; i < 3; i++)
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





