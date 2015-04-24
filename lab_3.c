#include<stdio.h>
#include<stdlib.h>
#include"assign3h.c"

void main()
{
        int numOfProc, cnt1, cnt2, time = 0, proc;
        int *proc_run = NULL;
        struct node *processes = NULL;
        
        printf("Enter total number of processes");
        scanf("%d",&numOfProc);
        
    for(cnt1 = 0; cnt1 < numOfProc; cnt1++)
        {
                processes = insert(processes,NULL);
        }
        proc_run = (int*)malloc(totalTime*sizeof(int));

        while(processes != NULL)
        {
                proc = min_deadline_exec(processes, time);
                if(proc < 0)
                {
                        proc *= -1;
                        processes = del(processes, proc);
                }
                proc_run[time] = proc;
                time++;
        }

        for(cnt1 = 1; cnt1 <= numOfProc; cnt1++)
        {
                printf("\nP[%d]", cnt1);
                for(cnt2 = 0; cnt2 < totalTime; cnt2++)
                {
                        if(proc_run[cnt2] == cnt1)
                                printf("*");
                        else
                                printf(" ");
                }
        }
        printf("\numOfProc");
        free(proc_run);
}
