#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;         // Process ID
    int arrival;    // Arrival Time
    int burst;      // Burst Time
    int completion; // Completion Time
    int turnaround; // Turnaround Time
    int waiting;    // Waiting Time
    int inQueue;    // Flag 
} Process;



void sortByArrival(int n, Process p[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival > p[j + 1].arrival) {
                Process temp = p[j];
                 p[j]=p[j+1];
                 p[j+1]=temp;
    
            }
        }
    }
}

int main() {
    int n, total_waiting = 0, total_turnaround = 0, quantum;
    float avg_waiting, avg_turnaround;
    
    printf("Enter the number of p: ");
    scanf("%d", &n);
    
    Process p[n];
    int original_burst[n]; 

   
    printf("Enter the arrival time and burst time of each process (AT BT):\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Process P%d: ", p[i].id);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
        original_burst[i] = p[i].burst;
        p[i].inQueue = 0; // Initialize flag
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    sortByArrival(n, p); //sorting

    int completed = 0, currentTime = p[0].arrival;
    int front = 0, rear = 0;
    int *queue = (int *)malloc(n * sizeof(int));
    queue[rear] = 0;
    p[0].inQueue = 1;

    
    while (completed != n) {
        int currentIdx = queue[front];
        front = (front + 1) % n;

        
        if (p[currentIdx].burst > quantum) {
            currentTime += quantum;
            p[currentIdx].burst -= quantum;
            printf("| P%d(%d) %d", p[currentIdx].id, quantum, currentTime);
        } else {
            currentTime += p[currentIdx].burst;
            printf("| P%d(%d) %d", p[currentIdx].id, p[currentIdx].burst, currentTime);
            p[currentIdx].burst = 0;
            p[currentIdx].completion = currentTime;
            p[currentIdx].turnaround = p[currentIdx].completion - p[currentIdx].arrival;
            p[currentIdx].waiting = p[currentIdx].turnaround - original_burst[currentIdx];
            total_turnaround += p[currentIdx].turnaround;
            total_waiting += p[currentIdx].waiting;
            completed++;
        }

     
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= currentTime && p[i].inQueue == 0 && p[i].burst > 0) {
                rear = (rear + 1) % n;
                queue[rear] = i;
                p[i].inQueue = 1;
            }
        }

       
        if (p[currentIdx].burst > 0) {
            rear = (rear + 1) % n;
            queue[rear] = currentIdx;
        }
    }

    // Calculate average times
    avg_turnaround = (float)total_turnaround / n;
    avg_waiting = (float)total_waiting / n;

    // Print process details
    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].arrival, original_burst[i], p[i].completion, p[i].turnaround, p[i].waiting);
    }
    printf("\nAverage Turnaround Time = %.2f\nAverage Waiting Time = %.2f\n", avg_turnaround, avg_waiting);

    free(queue);
    return 0;
}
