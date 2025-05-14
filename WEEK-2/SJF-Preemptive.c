#include<stdio.h>
struct gg{
    int at,bt,ct,tat,wt,rt;
    int ss;
};
int main(){
  int n;
  printf("Enter the Number of Process : ");
  scanf("%d",&n);
  struct gg x[n];
  printf("ENter the Arrival-Time and Burst-Time:\n");
  int bb[n];
  for(int i=0;i<n;++i){
  scanf("%d%d",&x[i].at,&x[i].bt);x[i].ss=-1;bb[i]=x[i].bt;}
  int vis[n];
  for(int i=0;i<n;++i) vis[i]=-1;
  int ind=0;
    while(1){
        int y=100000,yy=-1;
        for(int i=0;i<n;++i)
        if(vis[i]==-1 && x[i].at<=ind && x[i].bt<y){
            y=x[i].bt;yy=i;}
        if(yy!=-1){
            x[yy].bt--;
            if(x[yy].ss==-1) x[yy].ss=ind;
            if(x[yy].bt==0){
            vis[yy]=1;x[yy].ct=ind+1;}
        }
        ++ind;
        int k=1;
        for(int i=0;i<n;++i)
        if(vis[i]==-1){k=0;break;}
        if(k) break;
    }
    for(int i=0;i<n;++i){
        x[i].tat=x[i].ct-x[i].at;
        x[i].wt=x[i].tat-bb[i];
        x[i].rt=x[i].ss-x[i].at;
    }
    printf("Process\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\t\tRT\n");
    for(int i=0;i<n;++i)
    printf("P%d\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,x[i].at,bb[i],x[i].ct,x[i].tat,x[i].wt,x[i].rt);
}
