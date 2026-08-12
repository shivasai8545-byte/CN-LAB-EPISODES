#include <stdio.h>

int main()
{
    int data[100], div[20], temp[100];
    int datalen = 0, divlen = 0, i, j;
    char ch;

    printf("Enter the data(Binary): ");

    while ((ch = getchar()) != '\n')
    {
        if (ch == '1' || ch == '0')
        {
            data[datalen++] = ch - '0';
        }
    }

    printf("Enter the divisor(Binary): ");

    while ((ch = getchar()) != '\n')
    {
        if (ch == '1' || ch == '0')
        {
            div[divlen++] = ch - '0';
        }
    }

    /* Copy data into temp */
    for (i = 0; i < datalen; i++)
    {
        temp[i] = data[i];
    }

    /* Add zeros */
    for (i = 0; i < divlen - 1; i++)
    {
        temp[datalen + i] = 0;
    }

    /* Total length */
    int totallen = datalen + divlen - 1;

    /* Binary division */
    for (i = 0; i <= totallen - divlen; i++)
    {
        if (temp[i] == 1)
        {
            for (j = 0; j < divlen; j++)
            {
                temp[i + j] = temp[i + j] ^ div[j];
            }
        }
    }

    /* Print Data + CRC */
    for (i = 0; i < datalen; i++)
    {
        printf("%d", data[i]);
    }

    printf("(Data) + ");

    for (i = datalen; i < totallen; i++)
    {
        printf("%d", temp[i]);
    }

    printf("(CRC)\n");

    /* Print Transmitted Data */
    printf("Transmitted data(Data + CRC): ");

    for (i = 0; i < datalen; i++)
    {
        printf("%d", data[i]);
    }

    for (i = datalen; i < totallen; i++)
    {
        printf("%d", temp[i]);
    }

    printf("\n");

    return 0;
}
