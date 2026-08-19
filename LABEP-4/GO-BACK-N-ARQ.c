#include <stdio.h>

int main()
{
    int n, w;
    int i, j;
    int lost = 3;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter window size: ");
    scanf("%d", &w);

    printf("\n--- Sliding Window with Go-Back-N ---\n");

    for (i = 1; i <= n; i += w)
    {
        printf("\nWindow: ");

        for (j = i; j < i + w && j <= n; j++)
            printf("%d ", j);

        printf("\n");

        for (j = i; j < i + w && j <= n; j++)
        {
            printf("Sending frame %d... ", j);

            if (j == lost)
            {
                printf("LOST!\n");

                printf("Go-Back-N: Retransmitting from frame %d\n", j);

                for (; j < i + w && j <= n; j++)
                {
                    printf("Retransmitting frame %d... ", j);
                    printf("ACK received\n");
                }

                lost = -1;
                break;
            }

            printf("ACK received\n");
        }
    }

    printf("\nAll frames transmitted successfully.\n");

    return 0;
}
