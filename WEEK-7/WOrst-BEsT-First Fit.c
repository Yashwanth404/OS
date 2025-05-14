#include<stdio.h>
int n,m;
int b[10000],f[10000];
void print(int all[m]){
    printf("File.No\tFile_Name\tBlock_No\tBlock_Name\n");
    for(int i=0;i<m;++i)
        if(all[i]!=-1)
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1,f[i],all[i]+1,b[all[i]]);
        else
        printf("%d\t\t\t%d\t\t\t-\t\t\t-\n",i+1,f[i]);
}
void first(){
    int vis[n],all[m];
    for(int i=0;i<n;++i) vis[i]=-1;
    for(int i=0;i<m;++i) all[i]=-1;
    for(int i=0;i<m;++i){
        for(int r=0;r<n;++r)
        if(vis[r]==-1 && b[r]>=f[i]){
            vis[r]=1;all[i]=r;break;}}
    print(all);
}
void best(){
    int vis[n],all[m];
    for(int i=0;i<n;++i) vis[i]=-1;
    for(int i=0;i<m;++i) all[i]=-1;
    for(int i=0;i<m;++i){
        int x=1000000;int y=-1;
        for(int r=0;r<n;++r)
            if(vis[r]==-1 && b[r]>=f[i] && b[r]-f[i]<x){
                y=r;x=b[r]-f[i];}
        all[i]=y;
        if(y!=-1) vis[y]=1;
    }
    print(all);
}
void worst(){
    int vis[n],all[m];
    for(int i=0;i<n;++i) vis[i]=-1;
    for(int i=0;i<m;++i) all[i]=-1;
    for(int i=0;i<m;++i){
        int x=-1,y=-1;
        for(int r=0;r<n;++r)
            if(vis[r]==-1 && b[r]>=f[i] && x<b[r]-f[i]){
                x=b[r]-f[i];y=r;}
        if(y!=-1)
        vis[y]=1;all[i]=y;
    }
    print(all);
}
int main(){
    printf("Memonry Managemnt Scheme\n");
    printf("Enter the number of block and file : ");
    scanf("%d %d",&n,&m);
    printf("Enter the Block size:\n");
    for(int i=0;i<n;++i){
        printf("Block %d: ",i+1);
    scanf("%d",&b[i]);}
    printf("Enter the File size:\n");
    for(int i=0;i<m;++i){
        printf("File %d: ",i+1);
    scanf("%d",&f[i]);}
    while(1){
        int x;
        printf("Choice :\n1.First fit\n2.Best Fit\n3.Worst Fit\n4.Exit\n");
        scanf("%d",&x);
        if(x==4) break;
        else if(x==1) first();
        else if(x==2) best();
        else worst();
    }
}
