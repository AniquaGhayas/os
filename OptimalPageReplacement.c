#include <stdio.h>

int findOptimal(int pages[], int n, int frames[], int f, int index) {
    int far = -1, pos = -1;

    for (int i = 0; i < f; i++) {
        int j;
        for (j = index + 1; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > far) {
                    far = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == n) // frame page not used again
            return i;
    }
    return (pos == -1 ? 0 : pos);
}
int main() {
    int n, f;
    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter page sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    int frames[f];
    for (int i = 0; i < f; i++) frames[i] = -1;

    int faults = 0;

    for (int i = 0; i < n; i++) {
        int hit = 0;
        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                hit = 1;
                break;
            }
        }
        if (!hit) {
            int replace = -1;
            for (int j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    replace = j;
                    break;
                }
            }
            if (replace == -1)
                replace = findOptimal(pages, n, frames, f, i);

            frames[replace] = pages[i];
            faults++;
        }
    }
    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
