#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <cstdio>

LinkedList::LinkedList()
{
    this->head = nullptr;
    printf("> LinkedList criada.\n");
}

LinkedList::~LinkedList()
{

    // Implementar..

    printf("> LinkedList destruida.\n");
}

bool LinkedList::push_front(int key)
{
    Node *node = new Node{key, nullptr};
    if (!node)
        return false;

    node->next = this->head; // o next do novo NODE eh o atual primeiro (cabeca) da lista
    this->head = node;       // novo NODE eh o novo cabeca da lista
    return true;
}

bool LinkedList::pop_front()
{

    // Implementar..

    return true;
}

int LinkedList::get(int pos)
{

    // Implementar..

    return -1;
}

void LinkedList::print()
{
    Node *p = this->head;

    while (p)
    {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}