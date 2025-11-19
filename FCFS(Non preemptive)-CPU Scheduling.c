#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];
    float totalWT = 0, totalTAT = 0;

    printf("Enter burst times:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    wt[0] = 0;
    tat[0] = bt[0];

    for(int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
    }

    for(int i = 0; i < n; i++) {
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nP\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f", totalTAT / n);

    float throughput = (float)n / tat[n-1];
    printf("\nThroughput = %.2f processes/unit time\n", throughput);

    return 0;
}
