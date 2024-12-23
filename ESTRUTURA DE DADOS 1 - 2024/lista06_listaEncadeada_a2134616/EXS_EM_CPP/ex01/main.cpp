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

    // Testando pop_front
    llist->pop_front();
    llist->print();

    // Testando get
    cout << "Elemento na posicao 1: " << llist->get(1) << endl;

    delete llist; // Isso vai chamar o destrutor, que irá liberar a memória da lista

    return 0;
}