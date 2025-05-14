#include<stdio.h>
struct gg{
    int at,bt,ct,tat,wt,rt;
};
int n;
int main(){
  printf("Enter the No. of Process : ");
  scanf("%d",&n);
  struct gg x[n];
  printf("Enter the Arival Time - Burst Time \n");
  for(int i=0;i<n;++i)
  scanf("%d%d",&x[i].at,&x[i].bt);
  int vis[n];int ind=0;
  for(int i=0;i<n;++i) vis[i]=-1;
  while(1){
    for(int i=0;i<n;++i)
        if(vis[i]==-1 && x[i].at<=ind){
            x[i].ct=ind+x[i].bt;
            x[i].tat=x[i].ct-x[i].at;vis[i]=1;
            x[i].wt=x[i].tat-x[i].bt;ind=x[i].ct-1;
            x[i].rt=x[i].wt;
            break;
        }
        ++ind;int k=1;
        for(int i=0;i<n;++i)
        if(vis[i]==-1){k=0;break;}
        if(k) break;
    }
    printf("Process\t\tAT\t\tBT\t\tTAT\t\tWT\t\tRT\n");
    for(int i=0;i<n;++i)
    printf("p%d\t\t\t%d\t\t%d\t\t%d\t\t%d\t%d\n",i,x[i].at,x[i].bt,x[i].tat,x[i].wt,x[i].rt);
}
