#include <stdio.h>
#include <string.h>

int count_occurrences(int n, int len, char lines[n][len], char word[])
{
    int count = 0;

    // Percorre cada linha do array de strings
    for (int i = 0; i < n; i++)
    {
        // Para cada linha, busca a ocorrência da palavra usando strstr()
        char *ptr = lines[i]; // Inicia a busca a partir do início da linha
        while ((ptr = strstr(ptr, word)) != NULL)
        {
            count++;             // Incrementa o contador de ocorrências
            ptr += strlen(word); // Move o ponteiro para a próxima posição após a palavra encontrada
        }
    }

    return count;
}

int main()
{
    char v[5][200] = {
        "computer programming is the process of designing and building an executable computer program for accomplishing a specific computing task.",
        "programming involves tasks such as analysis, generating algorithms, profiling algorithms accuracy and resource consumption, and the implementation of algorithms in a chosen programming language.",
        "the source code of a program is written in one or more programming languages.",
        "the purpose of programming is to find a sequence of instructions that will automate the performance of a task for solving a given problem.",
        "the process of programming thus often requires expertise in several different subjects, including knowledge of the application domain, specialized algorithms, and formal logic."};

    int count = count_occurrences(5, 200, v, "process");
    printf("Número de ocorrências: %d\n", count);

    return 0;
}
