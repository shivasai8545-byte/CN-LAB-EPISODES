#include <stdio.h>
#include <string.h>

int main() {
    char stuffed[200], data[200];
    int i, count = 0, j = 0;

    printf("Enter stuffed bit string: ");
    scanf("%s", stuffed);

    for (i = 0; i < strlen(stuffed); i++) {

        data[j++] = stuffed[i];

        if (stuffed[i] == '1') {
            count++;

            if (count == 5) {
                i++;          // Skip stuffed 0
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    data[j] = '\0';

    printf("De-stuffed data: %s\n", data);

    return 0;
}
