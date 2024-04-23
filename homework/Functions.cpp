#define _CRT_SECURE_NO_WARNINGS 1
#include "Functions.h"
using namespace std;

void CenterText(int x, int y, int w, int h, const char* text)
{
	setcolor(YELLOW);
	setbkmode(TRANSPARENT);

	int wspace = (w - textwidth(text)) / 2;
	int hspace = (h - textheight(text)) / 2;

	outtextxy(x + wspace, y + hspace, text);

	setlinecolor(WHITE);
}

bool inArea(int mx, int my, int x, int y, int w, int h)
{
	if (mx > x && mx < x + w && my > y && my < y + h)
	{
		return true;
	}

	return false;
}

bool putButton(int x, int y, int w, int h, const char* text, int mx, int my, int msg_message, int r, int g, int b)
{
	if (mx > x && mx < x + w && my > y && my < y + h)
	{
		setfillcolor(RGB(r, g, b));
	}
	else
	{
		setfillcolor(RGB(r + 15, g + 15, b + 15));
	}

	setlinecolor(WHITE);

	fillroundrect(x, y, x + w, y + h, 5, 5);

	CenterText(x, y, w, h, text);

	if (msg_message == WM_LBUTTONDOWN && inArea(mx, my, x, y, w, h))
	{
		return true;
	}

	return false;
}

bool put_image_Button(int x, int y, int w, int h, IMAGE buttons[], int mx, int my, int msg_message, int index)
{
	if (mx > x && mx < x + w && my > y && my < y + h)
	{
		putimage(x, y, &buttons[index+1]);
	}
	else
	{
		putimage(x, y, &buttons[index]);
	}

	if (msg_message == WM_LBUTTONDOWN && inArea(mx, my, x, y, w, h))
	{
		return true;
	}

	return false;
}

bool put_image_Button(int x, int y, int w, int h, IMAGE buttons[], int mx, int my, int msg_message, int index, int des)
{
	int ox = 0;
	int oy = 0;
	
	if (des == 0)
	{
		ox = abs(mx - x - buttons[index].getwidth() / 2);
		oy = abs(my - y - buttons[index].getheight() / 2 + 10);

		if (ox + oy < (buttons[index].getwidth() / 2 - 80))
		{
			putimage(x, y, &buttons[index + 1]);		
		}
		else
		{
			putimage(x, y, &buttons[index]);
		}

		if (msg_message == WM_LBUTTONDOWN && inArea(mx, my, x, y, w, h))
		{
			return true;
		}

		return false;
	}


}

void playMusic(char pass_music[][100], int music_index)
{
	cout << music_index << endl;
	mciSendString(pass_music[music_index], NULL, 0, NULL);
	mciSendString("play bkmusic repeat", NULL, 0, NULL);
}

void hitDetermine(BlueKeys& vec_BK, int* type_text, int* num_text, ExMessage& msg)
{
	if (vec_BK.mx >= 190 && vec_BK.mx <= 210)
	{
		*num_text = 0;
		*type_text = 3;
		vec_BK.value_hit = true;
		msg.message = 0;
	}
	else if ((vec_BK.mx > 170 && vec_BK.mx <= 190) || (vec_BK.mx > 210 && vec_BK.mx <= 230))
	{
		*num_text = 0;
		*type_text = 2;
		vec_BK.value_hit = true;
		msg.message = 0;
	}
	else if ((vec_BK.mx > 200 && vec_BK.mx <= 170) || (vec_BK.mx > 230 && vec_BK.mx <= 260))
	{
		*num_text = 0;
		*type_text = 1;
		vec_BK.value_hit = true;
		msg.message = 0;
	}
}

void levelTextPut(int* type_text, int* num_text,int temp)
{
	int y = 0;

	if (temp == 0) { y = 175; }
	if (temp == 1) { y = 375; }

	switch (*type_text)
	{
	case -1:
		outtextxy(225, y, "    ");

		*num_text = 0;

		break;
	case 0:
		outtextxy(225, y, "Miss");

		if (*num_text == 30)
		{
			*num_text = 0;
			*type_text = -1;
		}
		else
		{
			(*num_text)++;
		}
		break;
	case 1:
		outtextxy(225, y, "Bad");

		if (*num_text == 30)
		{
			*num_text = 0;
			*type_text = -1;
		}
		else
		{
			(*num_text)++;
		}
		break;
	case 2:
		outtextxy(225, y, "Good");

		if (*num_text == 30)
		{
			(*num_text)++;
			*type_text = -1;
		}
		else
		{
			(*num_text)++;
		}
		break;
	case 3:
		outtextxy(225, y, "Perfect");

		if (*num_text == 30)
		{
			*num_text = 0;
			*type_text = -1;
		}
		else
		{
			(*num_text)++;
		}
		break;
	}
}

void readDataFile(int music_index, vector<BlueKeys>& vec_BK, char pass_musicData[][100])
{
	ifstream fin;

	BlueKeys bk_temp;

	fin.open(pass_musicData[music_index]);
	cout << pass_musicData[music_index] << endl;

	while (fin >> bk_temp.mx)
	{
		fin >> bk_temp.my;
		fin >> bk_temp.mtime;

		vec_BK.push_back(bk_temp);
	}

	fin.close();
}