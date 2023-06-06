#include <stdio.h>
int main()
{
int n,AT[20],BT[20],ST[20],CT[20],WT[20],TAT[20]; float total_tt =0;
float total_wt =0;
printf("How many process to be created?\n"); 
scanf("%d", &n);
printf("Enter the arrival time and burst time of processes\n"); for(int i=0; i<n; i++)
{
printf("Arrival time of process %d: ", i); scanf("%d", &AT[i]);
 printf("Burst time of process %d: ", i); scanf("%d", &BT[i]); }
int i; ST[0]=AT[0];

 for(i=0;i<n;i++) {
CT[i]=ST[i]+BT[i]; ST[i+1]=CT[i]; TAT[i]=CT[i]-AT[i]; WT[i]=TAT[i]-BT[i];
}
for(i=0;i<n;i++)
{
printf("AT\tBT\tCT\tTAT\tWT\t\n");
for(i=0;i<n;i++)
{ printf("%d\t%d\t%d\t%d\t%d\n",AT[i],BT[i],CT[i],TAT[i],WT[i]); total_tt = total_tt + TAT[i];
total_wt = total_wt + WT[i];
}
float avg_tt = total_tt/n;
float avg_wt = total_wt/n;
printf("\nAverage waiting time: %f\n", avg_wt);
printf("Average turnaround time: %f\n", avg_tt);
return 0;
}
return 0;
}

 