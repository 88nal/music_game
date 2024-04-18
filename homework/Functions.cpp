#define _CRT_SECURE_NO_WARNINGS 1
#include "Functions.h"
using namespace std;

void CenterText(int x, int y, int w, int h, const wchar_t* text)
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

bool putButton(int x, int y, int w, int h, const wchar_t* text, int mx, int my, int msg_message, int r, int g, int b)
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

void playMusic(wchar_t pass_music[3][100], int music_index)
{
	cout << music_index << endl;
	mciSendString(pass_music[music_index], NULL, 0, NULL);
	mciSendString(L"play bkmusic repeat", NULL, 0, NULL);
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
	/*else
	{
		*type_text_up = 0;
		vec_BK.value_hit = true;
		msg.message = 0;
	}*/
}

void levelTextPut(int* type_text_up, int* type_text_down, int* num_text_up, int* num_text_down)
{
	switch (*type_text_up)
	{
	case -1:
		outtextxy(225, 175, L"    ");

		*num_text_up = 0;

		break;
	case 0:
		outtextxy(225, 175, L"Miss");

		if (*num_text_up == 30)
		{
			cout << "miss ++" << endl;
			*num_text_up = 0;
			*type_text_up = -1;
		}
		else
		{
			(*num_text_up)++;
			cout << *num_text_up << endl;
		}
		break;
	case 1:
		outtextxy(225, 175, L"Bad");

		if (*num_text_up == 30)
		{
			cout << "Bad ++" << endl;
			*num_text_up = 0;
			*type_text_up = -1;
		}
		else
		{
			(*num_text_up)++;
			cout << *num_text_up << endl;
		}
		break;
	case 2:
		outtextxy(225, 175, L"Good");

		if (*num_text_up == 30)
		{
			cout << "Good ++" << endl;
			(*num_text_up)++;
			*type_text_up = -1;
		}
		else
		{
			(*num_text_up)++;
			cout << *num_text_up << endl;
		}
		break;
	case 3:
		outtextxy(225, 175, L"Perfect");

		if (*num_text_up == 30)
		{
			cout << "Perfect ++" << endl;
			*num_text_up = 0;
			*type_text_up = -1;
		}
		else
		{
			(*num_text_up)++;
			cout << *num_text_up << endl;
		}
		break;
	}

	switch (*type_text_down)
	{
	case -1:
		outtextxy(225, 375, L"    ");

		*num_text_down = 0;

		break;
	case 0:
		outtextxy(225, 375, L"Miss");
		(*num_text_down)++;

		if (*num_text_down == 50)
		{
			*num_text_down = 0;
			*type_text_down = -1;
		}
		break;
	case 1:
		outtextxy(225, 375, L"Bad");
		(*num_text_down)++;
		if (*num_text_down == 50)
		{
			*num_text_down = 0;
			*type_text_down = -1;
		}
		break;
	case 2:
		outtextxy(225, 375, L"Good");
		(*num_text_down)++;
		if (*num_text_down == 50)
		{
			*num_text_down = 0;
			*type_text_down = -1;
		}
		break;
	case 3:
		outtextxy(225, 375, L"Perfect");
		(*num_text_down)++;
		if (*num_text_down == 50)
		{
			*num_text_down = 0;
			*type_text_down = -1;
		}
		break;
	}
}

void readDataFile(int music_index, vector<BlueKeys>& vec_BK)
{
	ifstream fin;

	BlueKeys bk_temp;

	fin.open("data\\test.txt");

	while (fin >> bk_temp.mx)
	{
		fin >> bk_temp.my;
		fin >> bk_temp.mtime;

		vec_BK.push_back(bk_temp);
	}

	fin.close();
}