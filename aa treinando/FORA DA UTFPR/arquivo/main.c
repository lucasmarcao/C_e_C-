#include <stdio.h>
 
int main() {
  FILE *arquivo;
  arquivo = fopen("marcos.doc", "juliano é gay");
  fputs("eu odeio tudo que existe", arquivo);
  fclose(arquivo);
  return 0;
}