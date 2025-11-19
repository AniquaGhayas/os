#include <stdio.h>

int main() {
    int n, f, pages[50], frame[10], recent[10];
    int i, j, pos, faults = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page numbers (space separated): ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);   // NO COMMAS IN INPUT

    printf("Enter number of frames: ");
    scanf("%d", &f);   // This will work

    // initialize frames
    for(i = 0; i < f; i++) {
        frame[i] = -1;
        recent[i] = -1;
    }

    for(i = 0; i < n; i++) {
        found = 0;

        // check if page exists
        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                recent[j] = i;
                break;
            }
        }

        if(!found) {
            // find least recently used
            pos = 0;
            for(j = 1; j < f; j++)
                if(recent[j] < recent[pos])
                    pos = j;

            frame[pos] = pages[i];
            recent[pos] = i;
            faults++;
        }
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}
