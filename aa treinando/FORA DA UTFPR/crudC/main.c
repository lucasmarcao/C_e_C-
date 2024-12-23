#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEOPLE 10

typedef struct
{
  char nome[50];
  int idade;
} Pessoa;

Pessoa pessoas[MAX_PEOPLE];
int num_pessoas = 0;

void adicionar_pessoa()
{
  if (num_pessoas == MAX_PEOPLE)
  {
    printf("\n Nao é possivel adicionar mais pessoas. O banco de dados esta cheio.\n");
    return;
  }

  printf("\n Digite o nome da pessoa: ");
  scanf("%s", pessoas[num_pessoas].nome);
  printf("\n Digite a idade da pessoa: ");
  scanf("%d", &pessoas[num_pessoas].idade);

  num_pessoas++;
}

void listar_pessoas()
{
  printf("Listando as pessoas:\n");
  for (int i = 0; i < num_pessoas; i++)
  {
    printf("Pessoa %d: %s, %d anos\n", i, pessoas[i].nome, pessoas[i].idade);
  }
}

void editar_pessoa()
{
  int indice;
  printf("Digite o indice da pessoa que deseja editar: ");
  scanf("%d", &indice);
  if (indice < 0 || indice >= num_pessoas)
  {
    printf("O indice informado e invalido.\n");
    return;
  }

  printf("\n Digite o novo nome da pessoa: ");
  scanf("%s", pessoas[indice].nome);
  printf("\n Digite a nova idade da pessoa: ");
  scanf("%d", &pessoas[indice].idade);
}

void remover_pessoa()
{
  int indice;
  printf("Digite o indice da pessoa que deseja remover: ");
  scanf("%d", &indice);
  if (indice < 0 || indice >= num_pessoas)
  {
    printf("O indice informado é invalido.\n");
    return;
  }

  for (int i = indice; i < num_pessoas - 1; i++)
  {
    pessoas[i] = pessoas[i + 1];
  }
  num_pessoas--;
}

int main()
{
  int opcao;
  do
  {
    printf("\nMenu:\n");
    printf("1. Adicionar pessoa\n");
    printf("2. Listar pessoas\n");
    printf("3. Editar pessoa\n");
    printf("4. Remover pessoa\n");
    printf("0. Sair\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      adicionar_pessoa();
      break;
    case 2:
      listar_pessoas();
      break;
    case 3:
      editar_pessoa();
      break;
    case 4:
      remover_pessoa();
      break;
    case 0:
      printf("Saindo...\n");
      break;
    default:
      printf("Opcao invalida.\n");
      break;
    }
  } while (opcao != 0);

  return 0;
}