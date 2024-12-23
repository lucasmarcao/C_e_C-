#include "vectorlist.h"
#include <stdio.h>
#include <stdlib.h>

VectorList::VectorList() {
    this->size = 0;
    this->capacity = 5;
    this->data = new int[this->capacity];
}

int VectorList::push_back(int elem) {
    if (this->size == this->capacity) {
        return 0;
    }
    this->data[this->size] = elem;
    this->size++;
    return 1;
}

void VectorList::print() {
    printf("(%d/%d) ", this->size, this->capacity);
    for (int i = 0; i < this->size; i++) {
        printf("%d ", this->data[i]);
    }
    printf("\n");
}