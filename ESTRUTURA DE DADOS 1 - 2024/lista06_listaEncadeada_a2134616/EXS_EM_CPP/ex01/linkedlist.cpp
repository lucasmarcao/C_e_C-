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
    // Liberar a memória de todos os nós da lista
    Node *p = this->head;
    while (p)
    {
        Node *temp = p;
        p = p->next;
        delete temp; // Libera o nó atual
    }

    printf("> LinkedList destruida.\n");
}

bool LinkedList::push_front(int key)
{
    Node *node = new Node{key, nullptr};
    if (!node)
        return false;

    node->next = this->head; // O next do novo NODE é o atual primeiro (cabeça) da lista
    this->head = node;       // O novo NODE é o novo cabeça da lista
    return true;
}

bool LinkedList::pop_front()
{
    if (this->head == nullptr) // Lista vazia
        return false;

    Node *temp = this->head;       // Aponta para o primeiro nó
    this->head = this->head->next; // A cabeça da lista aponta para o próximo nó
    delete temp;                   // Libera a memória do primeiro nó
    return true;
}

int LinkedList::get(int pos)
{
    if (pos < 0)
        return -1; // Verifica se a posição é válida

    Node *p = this->head;
    int index = 0;

    while (p)
    {
        if (index == pos) // Se a posição for encontrada
            return p->key;

        p = p->next;
        index++;
    }

    return -1; // Retorna -1 se a posição estiver fora do alcance
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
