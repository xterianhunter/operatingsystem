#include<bits/stdc++.h>
using namespace std;

void sortAT(int bt[], int n, int at[], int ct[]){
    ct[n] = {0};
    stack<int> CoT;
    CoT.push(0);
    int popped;
    int max_at=0;
    for(int k=0; k<n; k++){
        max_at = max(at[k],max_at);
        
    // cout<<max_at<<'\n';
    }
    for(int i=0; i<=max_at; i++){
         for(int j=0; j<n; j++){
            if(at[j]==i){
                // cout<<i<<'\t'<<j<<'\n';
                ct[j] = CoT.top() + bt[j];
                // cout<<ct[j];
                CoT.push(ct[j]);
                // cout<<CoT.top()<<'\n';
                break;
            }
         }
    }
}

void findTAT(int ct[], int n, int tat[], int at[]){
    for(int i=0; i<n; i++){
        tat[i] = ct[i]-at[i];
        // cout<<tat[i]<<'\t';
    }
    // cout<<'\n';
}

void findWT(int bt[], int n, int wt[],int tat[]){
    for(int i=0; i<n; i++){
        wt[i]=tat[i]-bt[i];
        // cout<<wt[i]<<'\t';
    }
    // cout<<'\n';
}

void findAVG(int process[], int n, int bt[], int at[]){
    int wt[n],ct[n], tat[n], total_wt=0, total_tat=0;
    sortAT(bt, n, at, ct);
    findTAT(ct, n, tat, at);
    findWT(bt, n, wt,tat);

    printf("process\tat\tbt\tct\ttat\twt");
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d",process[i],at[i],bt[i],ct[i],tat[i],wt[i]);
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
    int bt[] = {6,5,10,6,4};
    int at[] = {0,1,4,7,9};
    int n = sizeof(processes)/sizeof(processes[0]);
    // sortAT(bt, n, at);
    findAVG(processes, n, bt, at);
    
    return 0;
}