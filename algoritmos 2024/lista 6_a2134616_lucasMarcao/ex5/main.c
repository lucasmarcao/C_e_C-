#include <stdio.h>
#include <string.h>

// Função para converter uma string para letras maiúsculas
void string_to_upper(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - ('a' - 'A');
        }
        i++;
    }
}

// Função para comparar duas strings independentemente do caso
int strcmp_plus(const char s1[], const char s2[])
{
    // Cópia das strings para não modificar as originais
    char s1_upper[strlen(s1) + 1];
    char s2_upper[strlen(s2) + 1];
    strcpy(s1_upper, s1);
    strcpy(s2_upper, s2);

    // Conversão das strings para maiúsculas
    string_to_upper(s1_upper);
    string_to_upper(s2_upper);

    // Comparação usando strcmp()
    return strcmp(s1_upper, s2_upper);
}

int main()
{
    int res = strcmp_plus("JOanna", "joanna");
    printf("res: %d\n", res); // Saída: res: 0 (strings iguais)
    return 0;
}
