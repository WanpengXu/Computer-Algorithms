#include <cstdio>
#include <algorithm>
using namespace std;
void MNS(int pi[],int n,int **size){
    // 初始化第一行
    for(int j=0;j<pi[1];j++)
        size[1][j]=0;
    for(int j=pi[1];j<=n;j++)
        size[1][j]=1;
    // 2->n-1行按状态转移方程计算
    for(int i=2;i<n;i++){
        for(int j=0;j<pi[i];j++)
            size[i][j]=size[i-1][j];
        for(int j=pi[i];j<=n;j++)
            size[i][j]=max(size[i-1][j],size[i-1][pi[i]-1]+1);
    }
    // 最后一行只算最后一列，单拎出来
    size[n][n]=max(size[n-1][n],size[n-1][pi[n]-1]+1);
}

void Traceback(int pi[],int **size,int n,int Net[],int &m){
    int j=n;// 列坐标（下端接线柱）
    m=0;
    for(int i=n;i>1;i--){// 行坐标（上端接线柱）
        if(size[i][j]!=size[i-1][j]){
            Net[m++]=i;
            j=pi[i]-1;
        }
    }
    // 这里要改，这两句明显只针对第一行，应和前面的n->2行分开
    // 第一行的上方格子不能用，只能特判
    if(j>=pi[1])
    // 如果下段接线柱pi[2]在pi[1]后面，那么上端接线柱1一定可以加入集合
        Net[m++]=1;
}

bool PrintMatrix(int **m,int r,int c,int pi[]){
    printf("            ");
    for (int i=1;i<=c;i++)
        printf("%4d",i);
    printf("\n");
    printf("            ");
    for (int i=1;i<=c;i++)
        printf("____");
    printf("\n");
    for (int i=1;i<=r;i++){
        printf("(%2d,%2d)  %2d|",i,pi[i],i);
        for (int j=1;j<=c;j++)
            printf("%4d",m[i][j]);
        printf("\n");
    }
    printf("\n");
    return true;
}



int main(){
    const int n=10;
    int pi[n+1]={0,2,4,7,8,5,6,9,3,10,1};
    // int pi[n+1]={0,8,7,4,2,5,1,9,3,10,6};
    int Net[n]={0};
    int m=0;
    int size[n+1][n+1]={0};
    int* psize[n+1];
    for(int i=0;i<(n+1);i++)
        psize[i]=size[i];
    MNS(pi,n,psize);
    PrintMatrix(psize,n,n,pi);
    Traceback(pi,psize,n,Net,m);
    for(int i=0;i<m;i++)
        printf("%d ",Net[i]);
    return 0;
}