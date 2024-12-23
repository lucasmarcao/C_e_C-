#include <stdio.h>
#include <stdlib.h>
#include "vectorlist.h"

int main() {
    VectorList* list = new VectorList();
    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    list->print();

    return 0;
}