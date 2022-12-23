
#include <stdio.h>
#include <conio.h>
#include "graphic.h"
#include<iostream>
using namespace std;

int x = 40, y = 20;
#define MAUNEN 176
#define MAUCHU 112

int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)	// special key
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return key_none;
	}

	return key_none;
}


//-------------------------Screen-------------------------
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}


//screen: goto [x,y]
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


//screen: get [x]
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}


//screen: get [y]
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}


void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void SetColor(int code) {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, code);
}

void BOX(int x, int y, int w, int h) {
	TextColor(122);
	//	SetColor(3);

	if (h <= 1 || w <= 1) return;
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);

	}

	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);

	}

	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);
}
void Box(int x, int y, int w, int h) {
	//TextColor(b_color);
	//for (int iy = y+1 ; iy <= y + h-1; iy++) {
	//	for (int ix = x+1; ix <= x + w-1; ix++) {
	//		gotoXY(ix, iy); cout << " ";
	//	}
	//}
	//SetColor(7);
	//gotoXY(x + 1, y + 1);
	//cout << s;

	//----------------------vien--------------
	SetColor(0);
	TextColor(160);
	if (h <= 1 || w <= 1) return;
	for (int ix = x; ix <= x + w; ix++) {
		SetColor(120);
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);

	}

	for (int iy = y; iy <= y + h; iy++) {
		SetColor(120);
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);

	}

	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);
	//	gotoXY(48, 23); cout << char(195);
	//	gotoXY(87, 23); cout << char(180);
}


void box(int x, int y, int w, int h, string nd, int b_color) {
	//TextColor(b_color);
	//for (int iy = y+1 ; iy <= y + h-1; iy++) {
	//	for (int ix = x+1; ix <= x + w-1; ix++) {
	//		gotoXY(ix, iy); cout << " ";
	//	}
	//}
	SetColor(110);
	gotoXY(x + 1, y + 1);
	cout << nd;
	//SetColor(0);
	//TextColor(160);
	//----------------------vien--------------
	//SetColor(12);
	TextColor(b_color);
	if (h <= 1 || w <= 1) return;
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);

	}

	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);

	}

	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);
	//	gotoXY(48, 23); cout << char(195);
	//	gotoXY(87, 23); cout << char(180);
}

//-----------hien thi str1 str 2
void Str(string str1, string str2) {
	BOX(55, 3, 85, 4);
	gotoXY(60, 5);
	cout << str1;
	BOX(55, 8, 85, 4);
	gotoXY(60, 10);
	cout << str2;
}
//---------------------------------------------------------





enum TRANGTHAI { UP, DOWN, LEFT, RIGHT, ENTER };
TRANGTHAI Key(int z) {
	if (z == 224) {
		char c = _getch();
		if (c == 72) return UP;
		if (c == 80) return DOWN;
		if (c == 77) return RIGHT;
		if (c == 75) return LEFT;

	}
	else if (z == 13) return ENTER;
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void AD() {
	Box(x, y, 35, 2);
	Box(x, y + 4, 35, 2);
	Box(x, y + 8, 35, 2);
	Box(x - 2, y - 2, 39, 14);
	box(x - 2, y - 4, 39, 2, "        -------INPUT MENU------        ", 120);
	gotoXY(x - 2, y - 2); cout << char(195);
	gotoXY(x + 37, y - 2); cout << char(180);
}

void ADD() {
	//int x = 30, y = 15;
	Box(x, y, 35, 2);
	Box(x, y + 4, 35, 2);
	Box(x, y + 8, 35, 2);
	Box(x, y + 12, 35, 2);
	Box(x, y + 16, 35, 2);
	Box(x - 2, y - 2, 39, 22);
	box(x - 2, y - 4, 39, 2, "                 MENU                 ", 120);
	gotoXY(x - 2, y - 2); cout << char(195);
	gotoXY(x + 37, y - 2); cout << char(180);

}

void Save() {
	Box(x, y, 35, 2);
	Box(x, y + 4, 35, 2);
	box(x - 2, y - 4, 39, 2, "             DO YOU SAVE ?            ", 120);
	Box(x - 2, y - 2, 39, 10);
	gotoXY(x - 2, y - 2); cout << char(195);
	gotoXY(x + 37, y - 2); cout << char(180);

}

void continuee(){
	Box(x, y, 35, 2);
	Box(x, y + 4, 35, 2);
	box(x - 2, y - 4, 39, 2, "         DO YOU WANT CONTINUE         ", 120);
	Box(x - 2, y - 2, 39, 10);
	gotoXY(x - 2, y - 2); cout << char(195);
	gotoXY(x + 37, y - 2); cout << char(180);
	
}
int menu(str Thaotac[], int n, void m()) {
	int tt = 0;
	int* mau = new int[n];
	for (int i = 0; i < n; i++)
		mau[i] = MAUCHU;
	mau[0] = MAUNEN;
	while (1) {
	//	clrscr(); giong xoa man hinh
		int k = y + 1;
		for (int i = 0; i < n; i++) {
			TextColor(mau[i]);
			gotoXY(x + 1, k);
			k += 4;
			cout << i + 1 << ". " << Thaotac[i];
		}
		m();

		int z = _getch();
		TRANGTHAI Trangthai = Key(z);
		switch (Trangthai) {
		case UP: {
			if (tt == 0) tt = n - 1;
			else tt--;
			break;
		}

		case DOWN: {
			if (tt == n - 1) tt = 0;
			else tt++;
			break;
		}

		case ENTER:
			return tt;
		}
		for (int i = 0; i < n; i++)
			mau[i] = MAUCHU;
		mau[tt] = MAUNEN;
	}
}



void Hienketqua(string s) {
	BOX(x + 50, y - 4, 80, 4);
	gotoXY(x + 51, y - 2);
	cout << "                                    KET QUA ";
	BOX(x + 50, y, 80, 10);

	gotoXY(x + 50, y); cout << char(195);
	gotoXY(x + 130, y); cout << char(180);
	gotoXY(x + 55, y + 2);
	cout << s;
}



