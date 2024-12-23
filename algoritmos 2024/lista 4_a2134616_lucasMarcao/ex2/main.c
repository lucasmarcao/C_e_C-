#include <stdio.h>

int main()
{
    int i;

    printf("DEC   HEX   CHR   DEC   HEX   CHR   DEC   HEX   CHR\n");

    for (i = 33; i <= 125; i++)
    {
        printf("%03d   %03X   %c   ", i, i, i);
        if (i % 3 == 2)

            printf("\n");
    }

    return 0;
}
