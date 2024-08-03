#include <stdio.h>
#include <limits.h>

typedef struct
{
  int id;
  int at;  // Arrival Time
  int bt;  // Burst Time
  int rt;  // Remaining Time
  int ct;  // Completion Time
  int tat; // Turnaround Time
  int wt;  // Waiting Time
} process; //  processess

void calculateTimes(process processs[], int n)

{
  int curr_time = 0, completed = 0;
  int min_rt, shortest = 0, finish_time;
  int total_tat = 0, total_wt = 0;
  printf("the gantt chart\n");

  // to execute untill all the programs completed
  while (completed != n)
  {
    // to find shortest processess
    min_rt = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      if (processs[i].at <= curr_time && processs[i].rt < min_rt && processs[i].rt > 0)
      {
        min_rt = processs[i].rt; // instead of burst time we should use remaining as its a preemptive
        shortest = i;
      }
    }

    // if no precess arrived just move
    if (min_rt == INT_MAX)
    {
      curr_time++;
      continue;
    }
     printf("P%d\t",processs[shortest].id);
    // one second of execution
    processs[shortest].rt--;
    curr_time++;

    if (processs[shortest].rt == 0)
    {
      completed++;
      finish_time = curr_time;
      processs[shortest].ct = finish_time;
      processs[shortest].tat = finish_time - processs[shortest].at;
      processs[shortest].wt = processs[shortest].tat - processs[shortest].bt;

      total_tat += processs[shortest].tat;
      total_wt += processs[shortest].wt;
    }
  }

  printf("\nprocess\tArrival\tBurst\tComp\tTurnaround\tWaiting\n");
  for (int i = 0; i < n; i++)
  {
    printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", processs[i].id,
           processs[i].at, processs[i].bt,
           processs[i].ct, processs[i].tat,
           processs[i].wt);
  }
  printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
  printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
}

int main()
{
  int n;

  printf("Enter the number of processesses: ");
  scanf("%d", &n);

  process processs[n];
  printf("Enter the arrival and burst time for each processess:\n");
  for (int i = 0; i < n; i++)
  {
    processs[i].id = i + 1;
    printf("processess P%d:\n", processs[i].id);
    printf("Arrival time: ");
    scanf("%d", &processs[i].at);
    printf("Burst time: ");
    scanf("%d", &processs[i].bt);
    processs[i].rt = processs[i].bt; // here  iam using remaining time
  }

  calculateTimes(processs, n);

  return 0;
}
