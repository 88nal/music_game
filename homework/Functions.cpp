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

void playMusic()
{
	mciSendString(L"open music\\MistyMemory.mp3 alias bkmusic", NULL, 0, NULL);
	mciSendString(L"play bkmusic repeat", NULL, 0, NULL);
}