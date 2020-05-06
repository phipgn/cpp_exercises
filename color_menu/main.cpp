#include <iostream>
#include <windows.h>
#include "menu.h"

using namespace std;

#define CLR_FOCUS 207
#define CLR_NORML 15

void option1() {
	cout << "Option 1" << endl;
	cin.get();
}

void option2() {
	cout << "Option 2" << endl;
	cin.get();
}

int main() {
	
	// declare menu options
	string options[] = {
			"Add new record" , 
			"Edit record", 
			"Delete record", 
			"Search record", 
			"List all records", 
			"Trash", 
			"Quit"};
	int optionsLen = sizeof(options)/sizeof(options[0]);

	// initialize class colorMenu
	ColorMenu colorMenu(options, optionsLen, CLR_FOCUS, CLR_NORML);
	
	// handle option choices
	do {
		int optionIndex = colorMenu.handleMenu();	
		switch(optionIndex) {
			case 0: 
				option1();
				break;
			case 1:
				option2();
				break;
			case 6:
				colorMenu.~ColorMenu();
				exit(EXIT_SUCCESS);
				break;
		}		
	} while (true);	

	return 0;
}
