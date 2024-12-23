#include <stdio.h>
#include <setjmp.h>

jmp_buf ex_buf__;

#define TRY                 \
  switch (setjmp(ex_buf__)) \
  {                         \
  case 0:                   \
    while (1)               \
    {
#define CATCH(x) \
  break;         \
  case x:
#define FINALLY \
  break;        \
  }             \
  default:
#define END_TRY }
#define THROW(x) longjmp(ex_buf__, x)

int divisao(int a, int b)
{
  if (b == 0)
  {
    printf("Gerando erro de divisao por zero\n");
    THROW(1);
  }

  return a / b;
}

int main()
{
  TRY
  {
    int resultado = divisao(10, 0);
    printf("Resultado da divisao: %d\n", resultado);
  }
  CATCH(1)
  {
    printf("Tratando erro de divisao por zero\n");
  }
  FINALLY
  {
    int tenta = divisao(20, 4);
    printf("\n %i", tenta);
    printf("\n Executando codigo da secao finally\n");
  }
  END_TRY;

  return 0;
}
