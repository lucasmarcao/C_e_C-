#include <stdio.h>
#include <stdlib.h>
#include "vectorlist.hpp"

// g++ *cpp  --> para executar

int main() {

    VectorList* list = new VectorList();
    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    list->push_back(8);

    // escreve print
    list->print();

    return 0;
}