#include<stdio.h>
#define max 30

int main()
{
    int i,j,n,bt[max] , at[max] , wt[max] , tat[max] , temp[max];
    float awt = 0, atat=0;          // Averate waiting and turnaround time

    printf("Enter number of process : ");
    scanf("%d",&n);

    printf("Enter the burst time of all the process : \n");

    for(i=0; i<n; i++)
        scanf("%d",&bt[i]);
    
    printf("Enter the arrival time of the process :\n");
    for(i=0; i<n; i++)
        scanf("%d",&at[i]);

    temp[0]=0;

    printf("process\tArrival Time\tburst time\twaiting time\tTurn around time\n");

    for(i=0; i<n; i++)
    {
        wt[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i]+bt[i];
        wt[i] = temp[i]-at[i];
        tat[i] = wt[i]+bt[i];

        awt = awt + wt[i];
        atat = atat + tat[i];

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],wt[i],tat[i]);
    }

    awt /= n;
    atat /= n;

    printf("Average waiting time = %f\n",awt);
    printf("Average turn around time = %f",atat);

}