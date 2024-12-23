#ifndef VECTORLIST_H
#define VECTORLIST_H

// Definicao do TAD Lista Sequencial
//  gcc *.c


struct VectorList {
    int size;
    int capacity;
    int* data;
};

typedef struct VectorList VectorList;

// Operacoes sobre o TAD Lista Sequencial

VectorList* list_create();
int list_push_back(VectorList* this, int elem);
void list_print(VectorList* this);

#endif

