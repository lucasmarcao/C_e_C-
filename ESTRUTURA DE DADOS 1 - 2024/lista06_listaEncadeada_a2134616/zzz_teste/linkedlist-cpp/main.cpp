#include <cstdio>
#include "linkedlist.h"

int main()
{

    LinkedList *llist = new LinkedList;

    for (int i = 0; i < 10; i++)
    {
        llist->push_front(i * 2);
        llist->print();
    }

    delete llist;

    return 0;
}