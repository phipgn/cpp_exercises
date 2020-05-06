#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct node {
	int id;
	node *next;
};

void insert_first(node *&first, node *q) {
	if (first == NULL) {
		first = q;
		return;
	} 
	q->next = first;
	first = q;
}

void insert_last(node *&first, node *q) {
	if (first == NULL) {
		first = q;
		return;
	} 
	node* last = first;
	while (last->next != NULL) last = last->next;
	last->next = q;
}

void swap(node* &p, node* &q) {
	int t = p->id;
	p->id = q->id;
	q->id = t; 
}

void print_nodes(node* p) {
	if (p == NULL) return;
	
	while (p != NULL) {
		printf("%3d -> ", p->id);
		p = p->next;
	}
	cout << " NULL\n";
}

void bubble_sort(node *&first, bool asc) {
	cout << "\nLinked list sorted ";
	asc ? cout << "ascending:\n" : cout << "descending:\n";
	
	if (first == NULL) return;
	
	node* p = first;
	node* q = p->next;
	
	do {
		while (q != NULL) {
		    if (asc && (q->id < p->id)) swap(p, q);
		    if (!asc && (q->id > p->id)) swap(p, q);
		    q = q->next;
		}
		p = p->next; 
		if (p == NULL) break;
		q = p->next;
	} while(true);
}

node* new_node(int id) {
    node *q = new node();
	q->id = id;
	q->next = NULL;
	return q;
}

int main() { 
	node *first = NULL;
	
	srand(time(0));
	for (int i = 0; i < 5; i++) {
		int id = rand() % 201 - 100;
		insert_last(first, new_node(id));
		print_nodes(first);
	}
	
	for (int i = 0; i < 5; i++) {
		int id = rand() % 201 - 100;
		insert_first(first, new_node(id));
		print_nodes(first);
	}
	
	bubble_sort(first, true);
	print_nodes(first);
	bubble_sort(first, false);
	print_nodes(first);
	
	return 0;
}
