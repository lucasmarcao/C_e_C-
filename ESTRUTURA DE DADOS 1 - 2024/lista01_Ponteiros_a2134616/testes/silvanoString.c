#include <stdio.h>
#include <string.h>

void print_str(char s[])
{
    int i = 0;
    for (; s[i] != 0; i++)
    {
        printf("%c-", s[i]);
    }
    printf("\b \n");
}

void replace_str(char s[], char tgt, char rep)
{
    if (tgt >= 'A' && tgt <= 'Z')
        tgt += 32;

    for (int i = 0; s[i] != 0; i++)
    {
        if (s[i] == tgt || s[i] == tgt - 32)
        {
            s[i] = rep;
        }
    }
}

int main()
{
    char str[] = "texto de TESTE";
    replace_str(str, 't', '$');
    print_str(str);

    char name[] = "John Doe";
    int age = 45;
    char str2[100];

    sprintf(str2, "Name: %s, Age: %d", name, age);
    printf("%s\n", str2);

    return 0;
}