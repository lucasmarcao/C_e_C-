#include <stdio.h>
#include <stdlib.h>
#include "vectorlist.h"

int main() {
    VectorList* list = new VectorList();

    for (int i = 0; i < 50; i++) {
        list->push_back(i*2);
    }
    list->print();

    delete list;

    return 0;
}