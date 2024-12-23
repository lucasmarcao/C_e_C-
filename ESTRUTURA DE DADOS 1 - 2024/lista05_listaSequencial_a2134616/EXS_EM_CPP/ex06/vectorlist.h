#ifndef VECTORLIST_H
#define VECTORLIST_H

// Definicao do TAD Lista Sequencial

struct VectorList {
    int size;
    int capacity;
    int* data;

    VectorList();
    int push_back(int elem);
    void print();
};

#endif