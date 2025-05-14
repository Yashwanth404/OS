#include<stdio.h>
struct gg{
    int at,bt,ct,tat,wt,rt;
    int ss;
};
int main(){
    int n;
    printf("Enter the no. of Process : ");
    scanf("%d",&n);
    struct gg x[n];
    int bb[n];int zz=10000000,z=-1;
    printf("Enter the Arrival-Time and Burst-Time :\n");
    for(int i=0;i<n;++i){
    scanf("%d%d",&x[i].at,&x[i].bt);x[i].ss=-1;bb[i]=x[i].bt;
        if(zz>x[i].at){
            zz=x[i].at;z=i;}
    }
    int q;
    printf("Enter the Quantum-Size : ");
    scanf("%d",&q);
    int a[n+1];
    int iq[n];
    for(int i=0;i<n;++i)   iq[i]=-1;
    int ind=zz;int f=0,r=1;
    a[0]=z;iq[0]=1;
    while(1){
        int t=a[f];
        f=(f+1)%n;
        if(x[t].ss==-1) x[t].ss=ind;
        if(x[t].bt<=q){iq[t]=0;
            x[t].ct=ind+x[t].bt;x[t].bt=0;ind=x[t].ct;}
        else{
            x[t].bt-=q;ind+=q;}
        for(int i=0;i<n;++i)
        if(iq[i]==-1 && x[i].at<=ind){
            iq[i]=1;a[r]=i;
            r=(r+1)%n;
        }
        if(x[t].bt!=0){
        a[r]=t;r=(r+1)%n;}
        int k=0;
        for(int i=0;i<n;++i)
        if(iq[i]==0) ++k;
        if(k==n) break;
    }
    for(int i=0;i<n;++i){
        x[i].tat=x[i].ct-x[i].at;
        x[i].wt=x[i].tat-bb[i];
        x[i].rt=x[i].ss-x[i].at;
    }
    printf("\nProcess\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\t\tRT\n");
    for(int i=0;i<n;++i)
    printf("P%d\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,x[i].at,bb[i],x[i].ct,x[i].tat,x[i].wt,x[i].rt);
}
