#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MARGIN_LEFT 2
#define MARGIN_TOP 2

using namespace std;

struct node {
	int id;
	node *next;
};

//Ham di chuyen con tro den vi tri nao do trong Console
void gotoxy(short x, short y) {
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x, y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

//Ham thay doi textcolor va backgroundcolor
void setColor(short x) { 
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, x);
}

// insert a node at the first position of the list
void insertFirst(node *&first, node *q) {
	// the list has no nodes
	if (first == NULL) {
		first = q;
		return;
	} 
	q->next = first;
	first = q; // pointer first now points to the node before it
}

// insert a node at the last position of the list
void insertLast(node *&first, node *q) {
	// the list has no nodes
	if (first == NULL) {
		first = q;
		return;
	} 
	// move to the last node of the list
	node *p = first;
	do {
		if (p->next == NULL) {
			p->next = q;
			return;
		} else {
			p = p->next;
		}
	} while(true);
}

void swapValues(node *&p, node *&q) {
	node *r = new node();
	// swap values
	r->id = p->id;
	p->id = q->id;
	q->id = r->id; 
}

void sortLinkedList(node *&first, bool asc) {
	
	cout << endl;
	cout << endl;
	cout << " Sort singly linked list";
	if (asc) 
		cout << " ascending!!!";
	else 
		cout << " descending!!!";
	
	node *p = first;
	node *q = p->next;
	
	do {
		while (q != NULL) {
			if (asc) {
				if (q->id < p->id) {
					swapValues(p, q);
				}
			} else {
				if (q->id > p->id) {
					swapValues(p, q);
				}
			}
			q = q->next;
		}
		
		// at this point, q = NULL
		
		p = p->next; // p points to next node of the list
		if (p == NULL) { // p == NULL, that means p is pointing to the last node, no more to sort
			break;
		}
		q = p->next;
		
	} while(true);
}

void printAllNodes(node *first) {
	cout << endl << endl;
	//setColor(15);
	//cout << " Show all nodes in singly linked list!!!" << endl;
	node *p = first;
	
	if (p == NULL) {
		return;
	}
	
	cout << " ";
	while (p != NULL) {
		if (p->id > 0) {
			setColor(175);
		}
		if (p->id < 0) {
			setColor(207);
		}
		if (p->id == 0) {
			setColor(159);
		}
		cout << " " << p->id << " ";
		setColor(15);
		cout << "->";
		p = p->next;
	}
	setColor(135);
	cout << " NULL ";
	setColor(15);
}

int main() { 
	
	node *first = NULL; // the first pointer of the list
	
	srand(time(0));
	
	for (int i = 0; i < 10; i++) {
		// random numbers from -100 to 100
		int id = rand()%201 - 100;
		// cout << id << " " << endl;
		node *q = new node();
		q->id = id;
		q->next = NULL;
		//insertFirst(first, q);
		insertLast(first, q);
		printAllNodes(first);
	}
	
	sortLinkedList(first, true);
	printAllNodes(first);
	sortLinkedList(first, false);
	printAllNodes(first);
	
	return 0;
}
