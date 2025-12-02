//SJF (Shortest Job First) is a CPU scheduling algorithm that selects the process with the smallest burst time first.

//✔ Minimizes average waiting time
//✔ Non-preemptive (your code uses this type)
//✘ Can cause starvation for long processes
//✘ Requires knowing burst times in advance

//SJF is optimal for reducing the average waiting time.


#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], p[n], wt[n], tat[n];
    
    // Input burst times
    for(i = 0; i < n; i++) {
        printf("Enter burst time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }

    // Sorting according to burst time (SJF)
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(bt[j] < bt[i]) {
                int t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = p[i]; p[i] = p[j]; p[j] = t;
            }
        }
    }

    wt[0] = 0;  // First process → zero waiting time

    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    // Turnaround times
    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    float avgwt = 0, avgtat = 0;
    for(i = 0; i < n; i++) {
        avgwt += wt[i];
        avgtat += tat[i];
    }

    avgwt /= n;
    avgtat /= n;

    float throughput = (float)n / tat[n-1];

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f", avgwt);
    printf("\nAverage Turnaround Time = %.2f", avgtat);
    printf("\nThroughput = %.4f processes/unit time\n", throughput);

    return 0;
}
