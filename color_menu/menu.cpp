#include <iostream>
#include <windows.h>
#include <conio.h>
#include "menu.h"

ColorMenu::ColorMenu(string* options2, int len2, int colorFocus2, int colorNormal2) {
	colorFocus = colorFocus2;
	colorNormal = colorNormal2;
	len = len2;

	options = new string[len];
	for (int i = 0; i < len; i++) {
		options[i] = options2[i];
		//cout << options[i] << endl;
	}
}

ColorMenu::~ColorMenu() {
	cout << "Object is being deleted" << endl;
}

int ColorMenu::getMenuLength() {
	return len;
}

void ColorMenu::printMenu(int focus) {

	system("cls");
	int k;

	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl;

	for (int i = 0; i < len; i++) {
		if (i == focus) {
			// set highlight color
			SetConsoleTextAttribute(hConsole, colorFocus);
		} else {
			// reset color
			SetConsoleTextAttribute(hConsole, colorNormal);
		}
		cout << "  " << i+1 << ". " << options[i] << endl;
	}
	// reset color
	SetConsoleTextAttribute(hConsole, colorNormal);
	cout << endl;
	//cout << "focus=" << focus << "; len=" << len << endl;
}

int ColorMenu::handleMenu() {

	int focus = 0;
	printMenu(focus);

	do {
		// Cac phim UP, DOWN, LEFT, RIGHT
		// nhan vao gia tri kep
		// la int 224 va char.
		// Do do ta phai co 2 lan
		// xu ly o day
		int ch = getch();
		if (ch == 0 || ch == 224) {
			char c = getch();
			switch(c) {
				// UP
				case 72:
					if (focus == 0) {
						focus = len - 1;
					} else {
						focus--;
					}
					break;
				// DOWN
				case 80:
					if (focus == len - 1) {
						focus = 0;
					} else {
						focus++;
					}
					break;
			}
		} else if (ch == 13){
			// ENTER
			return focus;
		}

		printMenu(focus);
	} while (true);

}
