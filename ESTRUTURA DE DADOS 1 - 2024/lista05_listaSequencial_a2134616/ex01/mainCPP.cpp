/*
Descrição: A função list_is_empty foi implementada para verificar se a
lista está vazia, ou seja, se o tamanho (size) da lista é igual a zero.
Se for, a lista está vazia, retornando verdadeiro (1);
caso contrário, retorna falso (0).
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectorlist.h"

/*
para varios arquivos:
   - em CPP:
 g++ mainCPP.cpp vectorlist.cpp vectorlist.h -o vectorListCPP.exe
   - em CPP:
 ./vectorListCPP.exe
*/

// Implementação da função para verificar se a lista está vazia
int list_is_empty(VectorList *list)
{
    if (list->size == 0)
    {             // Se o tamanho da lista for 0, está vazia
        return 1; // Retorna 1 (verdadeiro)
    }
    else
    {
        return 0; // Caso contrário, retorna 0 (falso)
    }
}

int main()
{
    VectorList *list = new VectorList();
    list->push_back(1);
    list->push_back(2);
    // oi
    list->push_back(3);
    list->print();

    // Testa se a lista está vazia
    if (list_is_empty(list))
    {
        printf("A lista esta vazia.\n");
    }
    else
    {
        printf("A lista nao esta vazia.\n");
    }

    return 0;
}
