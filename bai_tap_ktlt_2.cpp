#include<iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define MAX 20

using namespace std;

//Ham thay doi textcolor va backgroundcolor
void setColor(short x) { 
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, x);
}

// hoan doi gia tri cua 2 bien bat ky
void hoandoi(int &x, int &y) {
	int t = x;
	x = y;
	y = t;
}

// kiem tra xem mot so la chan hay le
bool laSoChan(int x) {
	return (x % 2 == 0) ? true : false;
}

// in ra cac phan tu trong mang a
void inMang(int a[]) {
	for (int i = 0; i < MAX; i++) {
		if (laSoChan(a[i])) {
			setColor(159); // mau xanh
		} else {
			setColor(207); // mau do
		}
		cout << " " << a[i] << " ";
		setColor(15);
		cout << " ";
	}
}

int main() {
	
	int *a = new int[MAX];
	int n = MAX;
	
	srand(time(0));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 101;
	}
	
	// truoc khi sap xep
	// in ra cac gia tri trong mang a
	cout << "Mang truoc khi sap xep:\n";
	inMang(a);

	int l = 0;		// index ben trai
	int r = n - 1;	// index ben phai
	
	cout << "\n\nPhan tach so chan va so le:";
	// tach phan tu le va chan
	while (l < r) {
		// tim so le dau tien tu ben phai
		while (laSoChan(a[r])) {
			r--;	// r = r - 1, r giam di 1 don vi
		}
		// tim so chan dau tien tu ben trai
		while (!laSoChan(a[l])) {
			l++;	// l = l + 1
		}
		// in ra cac index
		cout << "\nl=" << l << ",r=" << r << endl;
		// hoan doi gia tri cua so chan va so le
		hoandoi(a[l], a[r]);
	 	// in ra cac phan tu trong mang
		inMang(a);
	}
	hoandoi(a[l], a[r]);
 	cout << "\nl=" << l << ",r=" << r << endl;
	inMang(a);
	
	cout << "\n\nSap xep phan so le: \n";
	for (int i = 0; i < l; i++) {
		for (int j = i + 1; j < l; j++) {
			if (a[j] < a[i]) {
				hoandoi(a[i], a[j]);
			}
		}
	}
	inMang(a);
	
	cout << "\n\nSap xep phan so chan: \n";
	for (int i = r + 1; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) {
				hoandoi(a[i], a[j]);
			}
		}
	}
	inMang(a);
	
	return 0;
}
