#include<stdio.h>

void findWT(int bt[], int n, int wt[]){
    wt[0] = 0;
    for(int i=1; i<n; i++){
        wt[i] = wt[i-1]+bt[i-1];
    }
}

void findTAT(int bt[], int n, int tat[], int wt[]){
    for(int i=0; i<n; i++){
        tat[i] = wt[i]+bt[i];
    }
}

void findAVG(int process[], int n, int bt[]){
    int wt[n], tat[n], total_wt=0, total_tat=0;

    findWT(bt, n, wt);
    findTAT(bt, n, tat, wt);

    printf("process\tat\tbt\ttat\twt");
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d\t0\t%d\t%d\t%d",process[i],bt[i],tat[i],wt[i]);
        printf("\n");
        total_wt += wt[i];
        total_tat += tat[i];
    }
    
    printf("\n");
    float avgwt = (float)total_wt/(float)n;
    float avgtat = (float)total_tat/(float)n;
    printf("average waiting time: %f\n", avgwt);
    printf("average turnaround time: %f\n", avgtat);

}


int main(){
    int processes[] = {1,2,3,4,5};
    int bt[] = {8,7,6,5,4};
    int n = sizeof(processes)/sizeof(processes[0]);
    findAVG(processes, n, bt);
    
    return 0;
}
