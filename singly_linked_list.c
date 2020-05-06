#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node;

void push(node** head, node* p) {
    if (*head == NULL) {
        *head = p;
        return;
    }
    
    p->next = *head;
    *head = p;
}

void append(node** head, node* p) {
    if (*head == NULL) {
        *head = p;
        return;
    }
    
    node* last = *head;
    while (last->next != NULL)
        last = last->next;
    last->next = p;
}

void print_nodes(node* p) {
    while (p != NULL) {
        printf("%3d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

node* new_node(int data) {
    node* p = (node*) malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    return p;
}

int main() { 
    int n = 5;
    node* head = NULL;
    
    for (int i = 0; i < n; i++) {
        append(&head, new_node(i));
        print_nodes(head);
    }
    
    for (int i = 0; i < n; i++) {
        push(&head, new_node(i));
        print_nodes(head);
    }
    
    return 0;
}
