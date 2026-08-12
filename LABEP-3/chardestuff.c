#include <stdio.h>
#include <string.h>

int main() {
    char stuffed[200], data[200];
    char flag = '$';
    char esc = '/';

    int i, j = 0;
    int len;

    printf("Enter stuffed data: ");
    scanf("%s", stuffed);

    len = strlen(stuffed);

    // Skip starting FLAG
    i = 1;

    while (i < len - 1) {

        if (stuffed[i] == esc) {
            i++;  // Skip ESC
        }

        data[j++] = stuffed[i];
        i++;
    }

    data[j] = '\0';

    printf("De-stuffed data: %s\n", data);

    return 0;
}
