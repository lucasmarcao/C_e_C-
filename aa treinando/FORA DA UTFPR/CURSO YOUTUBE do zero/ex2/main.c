#include <stdio.h>
/*
Faça uma calculadora.

*/
int n1;
int n2;
int palavra;
int result;

int somar(arg1, arg2)
{
  int conta = arg1 + arg2;
  return conta;
}

int subtrair(arg1, arg2)
{
  int conta = arg1 - arg2;
  return conta;
}
int multiplicar(arg1, arg2)
{
  int conta = arg1 * arg2;
  return conta;
}
int dividir(arg1, arg2)
{
  int conta = arg1 / arg2;
  return conta;
}

int main(void)
{
  int oi = 0;
  do
  {
    printf("\n Selecione a operacao que deseja: \n");
    printf("{1: somar /2: subtrair /3: multiplicar /4: dividir / 5: sair } \n");
    printf("operacao = ");
    scanf("%i", &palavra);
    switch (palavra)
    {
    case 1:
      printf("Somar dois numeros. \n");
      printf("n1 = ");
      scanf("%i", &n1);
      printf("n2 = ");
      scanf("%i", &n2);
      printf("\n Resultado = ");
      printf("%i", somar(n1, n2));
      break;
    case 2:
      printf("Subtrair dois numeros. \n");
      printf("n1 = ");
      scanf("%i", &n1);
      printf("n2 = ");
      scanf("%i", &n2);
      printf("\n Resultado = ");
      printf("%i", subtrair(n1, n2));
      break;
    case 3:
      printf("multiplicar dois numeros. \n");
      printf("n1 = ");
      scanf("%i", &n1);
      printf("n2 = ");
      scanf("%i", &n2);
      printf("\n Resultado = ");
      printf("%i", multiplicar(n1, n2));
      break;
    case 4:
      printf("Dividir dois numeros. \n");
      printf("n1 = ");
      scanf("%i", &n1);
      printf("n2 = ");
      scanf("%i", &n2);
      printf("\n Resultado = ");
      printf("%i", dividir(n1, n2));
      break;
    case 5:
      oi = 5;
      break;
    default:
      printf("Opcao invalida.\n");
      break;
    }
  } while (oi != 5);

  return 0;
}