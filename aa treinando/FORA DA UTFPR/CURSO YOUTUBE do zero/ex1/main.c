#include <stdio.h>
/*
ler(n1)
ler(n2)
soma = n1+n2
escrever(soma)

*/

int main(void)
{
  int n1;
  int n2;
  int soma;
  printf("Somar dois numeros. \n");
  printf("n1 = ");
  scanf("%i", &n1);
  printf("n2 = ");
  scanf("%i", &n2);

  soma = n1 + n2;

  printf("TOTAL = ");
  printf("\n%i", soma);

  return 0;
}