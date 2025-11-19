#include <stdio.h>

int main() {
    int n, f, page[30], frame[10], i, j, k = 0;
    int faults = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page numbers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frame[i] = -1;

    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < f; j++)
            if (frame[j] == page[i])
                found = 1;

        if (!found) {
            frame[k] = page[i];
            k = (k + 1) % f;
            faults++;
        }
    }
    printf("Total Page Faults = %d\n", faults);
    return 0;
}
