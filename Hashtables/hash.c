#include <stdlib.h>
#include <stdio.h>

typedef struct _Node {
    int val;
    struct _Node *next;
} Node;

typedef struct _List {
    Node *head;
    Node *tail;
} List;

void listAppend(List *l, int val) {
    // Cria o novo nó
    Node *newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    // Torna ele o fim da lista
    l->tail->next = newNode;

    // Atualiza a cauda para o último nó
    l->tail = newNode; 
}

void testList(int n) {
    List l;
    // Cria um nó sentinela
    l.head = malloc(sizeof(Node));
    l.head->next = NULL;
    l.tail = l.head;
    for (int i = 0; i < n; i++) {
        int val = rand() % n;
        listAppend(&l, val);
    } 

    Node *cur = l.head->next;
    while (cur != NULL) {
        printf("%d -> ", cur->val);
    }
    printf("NULL\n");
    
}

int main() {
    int n = 10;
    testList(n);
    return 0;
}