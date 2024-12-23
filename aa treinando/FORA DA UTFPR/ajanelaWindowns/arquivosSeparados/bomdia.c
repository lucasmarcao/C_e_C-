// variavel exportada
int abcd = 1;

// variaveis locais a este arquivo fonte
static int xyz;
static char array[54];

// funcoes locais este arquivo fonte
static void func1(void);
static void func2(void);

void func_rg_xyz(void)
{
  // bla bla bla
  func1();
  // bla bla bla
}

void func_rg_xxx(void)
{
  // bla bla bla
  func2();
  // bla bla bla
}

void func1(void)
{
  // bla bla bla
  // bla bla bla
}

void func2(void)
{
  // bla bla bla
  // bla bla bla
}