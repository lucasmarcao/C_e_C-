/*

descrição:

*/
#include <iostream>
#include <cstdio>
#include "linkedlist.h"

// g++ main.cpp linkedlist.h linkedlist.cpp -o exercicio.exe
using namespace std;

int main()
{

    LinkedList *llist = new LinkedList;

    for (int i = 0; i < 10; i++)
    {
        llist->push_front(i * 2);
        llist->print();
    }

    // printf("\n acabou. \n");
    // cout << "\n acabou. \n";

    delete llist;

    return 0;
}