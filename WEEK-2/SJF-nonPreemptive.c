#include<stdio.h>
struct gg{
    int at,bt,ct,tat,wt,rt;
};
int main(){
  int n;
  printf("Enter the Number of Process : ");
  scanf("%d",&n);
  struct gg x[n];
  printf("ENter the Arrival-Time and Burst-Time:\n");
  for(int i=0;i<n;++i)
  scanf("%d%d",&x[i].at,&x[i].bt);
//   int a[10000];
  int vis[n];
  for(int i=0;i<n;++i) vis[i]=-1;
  int ind=0;
    while(1){
        int y=100000,yy=-1;
        for(int i=0;i<n;++i)
        if(vis[i]==-1 && x[i].at<=ind && x[i].bt<y){
            y=x[i].bt;yy=i;}
        if(yy!=-1){
            vis[yy]=1;
            x[yy].ct=ind+x[yy].bt;
            x[yy].tat=x[yy].ct-x[yy].at;
            x[yy].wt=x[yy].tat-x[yy].bt;
            x[yy].rt=x[yy].wt;vis[yy]=1;ind+=x[yy].bt-1;
        }
        ++ind;
        int k=1;
        for(int i=0;i<n;++i)
        if(vis[i]==-1){k=0;break;}
        if(k) break;
    }
    printf("Process\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\t\tRT\n");
    for(int i=0;i<n;++i)
    printf("P%d\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,x[i].at,x[i].bt,x[i].ct,x[i].tat,x[i].wt,x[i].rt);
}
