#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, completed = 0, seek = 0;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n], done[n];
    printf("Enter requests: ");
    for(i = 0; i < n; i++) { scanf("%d", &req[i]); done[i] = 0; }

    printf("Enter initial head: ");
    scanf("%d", &head);

    while(completed < n) {
        int min = 999, idx = -1;
        for(i = 0; i < n; i++)
            if(!done[i] && abs(req[i] - head) < min) {
                min = abs(req[i] - head);
                idx = i;
            }
        seek += min;
        head = req[idx];
        done[idx] = 1;
        completed++;
    }

    printf("Total Seek Time: %d\n", seek);
    return 0;
}
