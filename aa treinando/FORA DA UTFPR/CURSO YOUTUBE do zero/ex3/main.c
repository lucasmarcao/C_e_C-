#include <stdio.h>
#include <string.h>
#include <math.h>

/*
Fazer um programa que faz a formula de baskara.
*/
int a;
int b;
int c;

float delta(int arg1, int arg2, int arg3)
{
  float value = (arg2 * arg2) - (4 * arg1 * arg3);
  return value;
}

float valor1(float deltaarg, int arg1, int arg2)
{
  float resp = (-arg2 + sqrt(deltaarg)) / (arg1 * 2);
  return resp;
}

float valor2(float deltaarg, int arg1, int arg2)
{
  float resp = (-arg2 - sqrt(deltaarg)) / (arg1 * 2);
  return resp;
}

int main(void)
{
  char pergunta[70];
  int cont = 1;
  do
  {
    if (cont == 2)
    {
      printf("\n Deseja realizar a operacao novamente? S / N \n");
      gets(pergunta);
      if (strcmp(pergunta, "S") == 0)
      {
        cont = 1;
      }
    }
    if (cont == 1)
    {
      // entrada
      printf("Digite o valor de A. \n");
      scanf("%i", &a);

      printf("Digite o valor de B. \n");
      scanf("%i", &b);

      printf("Digite o valor de C. \n");
      scanf("%i", &c);
      // saida
      printf("\n A sua expressao ficou assim: \n");
      printf("\n%i", a);
      if (b >= 0)
      {
        printf("x^2 + ");
      }
      else
      {
        printf("x^2 ");
      }
      printf("%i", b);
      if (c >= 0)
      {
        printf("x + ");
      }
      else
      {
        printf("x ");
      }
      printf("%i", c);
      printf(" = 0.");
      // processamento
      printf("\n");
      float deltavariavel = delta(a, b, c);

      if (deltavariavel < 0)
      {
        printf("Delta deu: %f", deltavariavel);
        printf("já que ele é negativo, não da pra fazer");
      }
      else
      {
        printf("Delta deu: %f", deltavariavel);
        float valor1variavel = valor1(deltavariavel, a, b);
        printf("\n O primeiro valor de X(conta de mais) e: %f", valor1variavel);
        float valor2variavel = valor2(deltavariavel, a, b);
        printf("\n O segundo valor de X(conta de menos) e: %f", valor2variavel);
        printf("\n");
      }
    }
    cont = 2;
  } while (strcmp(pergunta, "N") != 0);
  return 0;
}