#include<process.h>
#include<iostream>
#include"KeyEvent.h"
using namespace std;
unsigned int __stdcall mythread(void*)
{
	int i = 0;
	while (1)
	{
		cout << GetCurrentThreadId() << ": " << i++ << endl;
		Sleep(500);
	}
		return 0;
	}
	unsigned int __stdcall keyEvent(void*) {
		KeyEvent k;
		int i;
		while (1) {
			i = k.getkey();
			switch (i) {
			case 37: cout << "Left Key Pressed." << endl; break;
			case 38: cout << "Up Key Pressed." << endl; break;
			case 39: cout << "Right Key Pressed." << endl; break;
			case 40: cout << "Down Key Pressed." << endl; break;
			}
		}
		return 0;
	}
	/*
	int main() {
		HANDLE handleA, handleB;

		handleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
		handleB = (HANDLE)_beginthreadex(0, 0, &keyEvent, (void*)0, 0, 0);

		WaitForSingleObject(handleA, INFINITE);
		WaitForSingleObject(handleB, INFINITE);

		CloseHandle(handleA);
		CloseHandle(handleB);

		return 0;



	}
	*/