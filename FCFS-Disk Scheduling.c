//FCFS (First Come First Serve) disk scheduling handles disk I/O requests in the exact order they arrive.
//It does not reorder or optimize requests — it simply serves the first request first.

//✔ Simple to implement
//✔ Fair to all processes
//✘ Can result in long seek time if requests are scattered on different tracks

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, seek = 0;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter requests: ");
    for(i = 0; i < n; i++) scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(i = 0; i < n; i++) {
        seek += abs(req[i] - head);
        head = req[i];
    }

    printf("Total Seek Time: %d\n", seek);
    return 0;
}
