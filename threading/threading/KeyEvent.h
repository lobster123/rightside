#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

enum { BLACK, D_BLUE, D_GREEN, D_SKYBLUE, D_VIOLET };
void gotoXY(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void setColor(char color, char backGround) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (backGround << 4) + color);
}
void clearConsole() {
	system("cls");
}
class KeyEvent {
private:
	HANDLE hln;
	COORD keyWhere;
	DWORD EventCount;
	INPUT_RECORD InRec;
	DWORD NumRead;
	int downKey;
public:
	KeyEvent() {
		hln = GetStdHandle(STD_INPUT_HANDLE);
		EventCount = 1;
	}
	int getkey() {
		ReadConsoleInput(hln, &InRec, 1, &NumRead);
		if (InRec.EventType == KEY_EVENT) {
			if (InRec.Event.KeyEvent.bKeyDown) {
				downKey = InRec.Event.KeyEvent.wVirtualKeyCode;
				return downKey;
			}
			else {
				return -1;
			}
		}
		return -1;
	}
};