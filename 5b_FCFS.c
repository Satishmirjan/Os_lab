#include <stdio.h>

typedef struct {
    int id;
    int at; // Arrival Time
    int bt; // Burst Time
    int ct; // Completion Time
    int tat; // Turnaround Time
    int wt; // Waiting Time
} Process;

void sortProcessesByArrivalTime(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                // Swap processes
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void calculateTimes(Process p[], int n) {
    int total_tat = 0, total_wt = 0;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (time < p[i].at) {
            time = p[i].at;
        }

        p[i].ct = time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        total_tat += p[i].tat;
        total_wt += p[i].wt;

        time = p[i].ct;
    }

    // Print results
    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Process P%d:\n", p[i].id);
        printf("Arrival time: ");
        scanf("%d", &p[i].at);
        printf("Burst time: ");
        scanf("%d", &p[i].bt);
    }

    sortProcessesByArrivalTime(p, n);
    calculateTimes(p, n);

    return 0;
}
