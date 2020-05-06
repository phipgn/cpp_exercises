#include <iostream>
#include <sstream>

using namespace std;

// in n so chan
void printEvenNumbers(int n) {
	
	cout << "In ra " << n << " so chan dau tien" << endl;
	
	int count = 0;
	int i = 0;
	do {		
		cout << i << " ";
		count++;		
		i += 2;
	} while (count < n);
}

// in n so le
void printOddNumbers(int n) {
	
	cout << "In ra " << n << " so le dau tien" << endl;
	
	int count = 0;
	int i = 1;
	do {
		cout << i << " ";
		count++;
		i += 2;
	} while (count < n);
}

// xac dinh xem 1 so co phai la so nguyen to hay khong
bool isPrime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

// in n so nguyen to dau tien
void printPrimeNumbers(int n) {
	
	cout << n << " so nguyen to dau tien: " << endl;
	
	int count = 0;
	int i = 2;
	do {
		if (isPrime(i)) {
			cout << i << " ";
			count++;
		}
		i++;
	} while (count < n);
}

// In ra n so dau tien chia het cho mot so m bat ky
void printNumbersWhichCanBeWhollyDevided(int n, int m) {
	
	cout << n << " so dau tien chia het cho " << m << endl;
	
	int count = 0;
	int i = m;
	do {
		cout << i << " ";
		count++;
		i += m;		
	} while (count < n);
}

// chuyen doi so thap phan sang nhi phan
long decimalToBinary(int n) {
	
    int remainder; 
 	long binary = 0, i = 1;
  
    while(n != 0) {
        remainder = n % 2;
        n = n / 2;
        binary = binary + (remainder * i);
        i = i * 10;
    }
    return binary;
}

int greatestCommonDivisor(int a, int b) {
	int gcd = 1;
	for (int i = 1; i <= a && i <= b; i++) {
		if (a % i == 0 && b % i == 0) {
			gcd = i;
		}
	}
	return gcd;
}

//Tim USCLN, BSCNN cua a va b
int leastCommonMultiple(int a, int b) {
	int minMultiple = (a > b) ? a : b;

    // Always true
    while(1)
    {
        if( minMultiple % a == 0 && minMultiple % b == 0 )
        {
            break;
        }
        ++minMultiple;
    }
    return minMultiple;
}

// only takes number
int getInputNumber() {
	string input = "";
	int myNumber = 0;
	getline(cin, input);	
	stringstream myStream(input);
	if (myStream >> myNumber) {
		return myNumber;
	}
	return -1;
}

int printMenu() {

	// xoa man hinh
 	system("cls");

	cout << "+-------------------+" << endl;
	cout << "| Bai tap KTLT so 1 |" << endl;
	cout << "+-------------------+" << endl;
	
	cout << "1. In ra n so chan dau tien" << endl;
	cout << "2. In ra n so le dau tien" << endl;
	cout << "3. In ra n so nguyen to dau tien" << endl;
	cout << "4. In ra n so dau tien chia het cho mot so m bat ky" << endl;
	cout << "5. Chuyen doi so thap phan sang nhi phan" << endl;
	cout << "6. Tim USCLN, BSCNN cua a va b" << endl;
	cout << "7. Exit" << endl;
	cout << "Chon chuc nang: ";
	
	// make sure only input numbers
	int myNumber = getInputNumber();
	if (myNumber < 1 || myNumber > 7) {
		return -1;
	}
	
	return myNumber;
}

int main(int argc, char** argv) {
	
	int number = -1;
	int m, n;
	bool quit = false;
	do {
		number = printMenu();
		
		if (number == -1) {
			cout << "Ban da nhap vao mot so khong hop le!!!" << endl;
			cin.get(); // tam dung chuong trinh
		}
		
		system("cls");
		
		switch(number) {
			// in n so chan
			case 1:
				cout << "Nhap n: ";
				n = getInputNumber();
				printEvenNumbers(n);
				cin.get();
				break;
			// in n so le
			case 2:
				cout << "Nhap n: ";
				n = getInputNumber();
				printOddNumbers(n);
				cin.get();
				break;
			// in n so nguyen to dau tien
			case 3:
				cout << "Nhap n: ";
				n = getInputNumber();
				printPrimeNumbers(n);
				cin.get();
				break;
			// in ra n so dau tien chia het cho mot so m bat ky
			case 4:
				cout << "Nhap n: ";
				n = getInputNumber();
				cout << "Nhap m: ";
				m = getInputNumber();
				printNumbersWhichCanBeWhollyDevided(n, m);
				cin.get();
				break;
			// chuyen so thap phan sang nhi phan
			case 5:
				cout << "Nhap n: ";
				n = getInputNumber();
				cout << decimalToBinary(n);
				cin.get();
				break;
			case 6:
				cout << "Nhap n: ";
				n = getInputNumber();
				cout << "Nhap m: ";
				m = getInputNumber();
				cout << "UCSLN cua " << n << " va " << m << " la: " << greatestCommonDivisor(n, m) << endl; // uoc so chung lon nhat
				cout << "BSCNN cua " << n << " va " << m << " la: " << leastCommonMultiple(n, m) << endl; // boi so chung nho nhat
				cin.get();
				break;
			case 7: 
				cout << "Chao tam biet!!!";
				quit = true;
				break;
		}
		
		
	} while (!quit);
	
	return 0;
}
