#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter requests: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head: ");
    scanf("%d", &head);

    int disk_end = 199;  
    int seek = 0;
    // Sort requests (ascending)
    for(i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(req[j] < req[i]) {
                int t = req[i];
                req[i] = req[j];
                req[j] = t;
            }
    int idx = 0;
    while(idx < n && req[idx] < head)
        idx++;
    // Move right first
    for(i = idx; i < n; i++) {
        seek += abs(req[i] - head);
        head = req[i];
    }
    // Go to the end of disk
    seek += abs(disk_end - head);
    head = disk_end;
    // Move left
    for(i = idx - 1; i >= 0; i--) {
        seek += abs(req[i] - head);
        head = req[i];
    }
    printf("Total Seek Time = %d\n", seek);
    return 0;
}
