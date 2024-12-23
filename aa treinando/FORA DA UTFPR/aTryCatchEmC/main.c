#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

jmp_buf jmpbuf;

void func()
{
  printf("Entrando em func()\n");
  int d = rand();
  printf("%i", d);
  printf("\n ");
  if (d % 2 == 0)
  {
    printf("Gerando excecao\n");
    longjmp(jmpbuf, 1);
  }

  printf("Saindo de func()\n");
}

int main()
{
  int val = setjmp(jmpbuf);

  if (val == 0)
  {
    printf("Primeira vez que setjmp() e chamada\n");
    func();
  }
  else
  {
    printf("setjmp() foi chamada pela segunda vez, val = %d\n", val);
    printf("Tratando excecao\n");
  }

  return 0;
}
