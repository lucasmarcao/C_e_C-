// #pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Definicao do TAD Lista Encadeada

class Node
{
public:
    int key;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList();
    ~LinkedList();
    bool push_front(int key);
    bool pop_front();
    int get(int pos);
    void print();
};

#endif