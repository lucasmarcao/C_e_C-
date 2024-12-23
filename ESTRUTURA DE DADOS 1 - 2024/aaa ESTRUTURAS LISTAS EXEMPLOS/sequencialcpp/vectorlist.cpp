#include "vectorlist.hpp"
#include "stdio.h"
#include "stdlib.h"

//  gcc *.c  -> para executar

VectorList *list_create()
{
    VectorList *list = new VectorList;
    list->size = 0;
    list->capacity = 5;
    list->data = new int[list->capacity];
    return list;
}

int list_push_back(VectorList *isso, int elem)
{
    if (isso->size == isso->capacity)
    {
        list_print(isso);
        return 0;
    }
    isso->data[isso->size] = elem;
    isso->size++;
    list_print(isso);
    return 1;
}

void list_print(VectorList *isso)
{
    printf("(%d/%d) ", isso->size, isso->capacity);
    for (int i = 0; i < isso->size; i++)
    {
        printf("%d ", isso->data[i]);
    }
    printf("\n");
}
