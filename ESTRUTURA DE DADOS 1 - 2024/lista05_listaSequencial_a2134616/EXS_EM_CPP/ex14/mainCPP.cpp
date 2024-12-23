/*
Descrição: A função `list_concat` deve concatenar os elementos da lista `list2` ao final de
`list1`, respeitando a capacidade de `list1`. A função começa verificando quanto espaço há
disponível em `list1` para adicionar elementos de `list2`. Em seguida, ela copia os elementos
de `list2` para `list1`, até que a capacidade de `list1` seja atingida ou que todos os elementos
de `list2` sejam copiados. A função retorna a quantidade de elementos efetivamente adicionados.
*/

#include "vectorlist.h"
#include <stdio.h>
#include <stdlib.h>

/*
para varios arquivos:
   - em CPP:
 g++ mainCPP.cpp vectorlist.cpp vectorlist.h -o vectorListCPP.exe
   - em CPP:
 ./vectorListCPP.exe
*/

// Função para concatenar list2 ao final de list1
int list_concat(VectorList *list1, VectorList *list2)
{
    int countAdded = 0; // Contador dos elementos adicionados

    // Verifica o espaço disponível em list1
    int spaceAvailable = list1->capacity - list1->size;

    // Se há espaço em list1, copiamos os elementos de list2 para list1
    for (int i = 0; i < list2->size && countAdded < spaceAvailable; i++)
    {
        list1->data[list1->size] = list2->data[i];
        list1->size++;
        countAdded++; // Incrementa o contador de elementos adicionados
    }

    // Retorna a quantidade de elementos adicionados
    return countAdded;
}

int main()
{
    // Exemplo de uso da função list_concat

    // Criação da lista 1
    VectorList *list1 = new VectorList();
    list1->push_back(1);
    list1->push_back(2);
    list1->push_back(3);

    // Criação da lista 2
    VectorList *list2 = new VectorList();
    list2->push_back(4);
    list2->push_back(5);
    list2->push_back(6);

    // Imprime a lista original
    printf("Lista 1 original: ");
    list1->print();

    printf("Lista 2: ");
    list2->print();

    // Chama a função para concatenar list2 em list1
    int elementsAdded = list_concat(list1, list2);

    // Imprime as listas após a concatenação
    printf("Lista 1 após concatenação: ");
    list1->print();

    // Imprime a quantidade de elementos adicionados
    printf("Quantidade de elementos adicionados: %d\n", elementsAdded);

    return 0;
}
