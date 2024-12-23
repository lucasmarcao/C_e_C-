#include "stdio.h"
#include "stdlib.h"
#include "vectorlist.hpp"

//  gcc *.c  -> para executar


int main() {
    VectorList* list = list_create();
    list_push_back(list, 6);
    list_push_back(list, 8);
    list_push_back(list, 9);
    list_push_back(list, 1);
    list_push_back(list, 7);
    list_push_back(list, 4);
    list_push_back(list, 0);
    // list_print(list);

    return 0;
}

