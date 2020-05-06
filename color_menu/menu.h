#include <iostream>

using namespace std;

class ColorMenu{
	
	private:
		int colorFocus;
		int colorNormal;
		int len;
		string* options;
		
	public:
		ColorMenu(string*, int, int, int);
		~ColorMenu();
		int getMenuLength();
		void printMenu(int);
		int handleMenu();
		
};
