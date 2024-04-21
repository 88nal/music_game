#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <graphics.h>
using namespace std;

class Keys
{
public:
	
};

class BlueKeys : public Keys
{
public:

	int mx;
	int my;
	int mtime;
	bool value_put = false;
	bool value_hit = false;
	int h = 100;
	int w = 15;

	void show();
};

//class Sence
//{
//public:
//	virtual void open();
//};