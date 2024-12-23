#include <stdio.h>

void int_to_string(int number, char converted[])
{
    sprintf(converted, "%d", number);
}

int main()
{
    char num[11];
    int_to_string(512, num);
    printf("%s\n", num); // Saída: "512"
    return 0;
}
