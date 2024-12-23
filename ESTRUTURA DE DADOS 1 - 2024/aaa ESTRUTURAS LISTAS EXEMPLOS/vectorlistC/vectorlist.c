#include "vectorlist.h"
#include <stdio.h>
#include <stdlib.h>

//  gcc *.c  -> para executar

VectorList* list_create() {
    VectorList* list = malloc(sizeof(VectorList));
    list->size = 0;
    list->capacity = 5;
    list->data = malloc(sizeof(int) * list->capacity);
    return list;
}

int list_push_back(VectorList* this, int elem) {
    if (this->size == this->capacity) {
        list_print(this);
        return 0;
    }
    this->data[this->size] = elem;
    this->size++;
    list_print(this);
    return 1;
}

void list_print(VectorList* this) {
    printf("(%d/%d) ", this->size, this->capacity);
    for (int i = 0; i < this->size; i++) {
        printf("%d ", this->data[i]);
    }
    printf("\n");
}

