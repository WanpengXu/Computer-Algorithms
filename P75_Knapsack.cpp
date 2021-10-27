#include <cstdio>
#include <algorithm>
using namespace std;
template<typename Type>
void Knapsack(Type* v,int* w,int c,int n,Type** m){
    // 初始化第n行
    int jMax=min(w[n]-1,c);
    for(int j=0;j<=jMax;j++)
        m[n][j]=0;
    for(int j=w[n];j<=c;j++)
        m[n][j]=v[n];
    // 第n-1->2行按状态转移方程计算
    for(int i=n-1;i>1;i--){
        jMax=min(w[i]-1,c);
        for(int j=0;j<=jMax;j++)
        // 装不了的时候，把下一行抄上来，使用其所对应情况的最优解
            m[i][j]=m[i+1][j];
        for(int j=w[i];j<=c;j++)
        // 能装的时候，考虑一下是不是装了（下一行背包剩余空间最优解+v[i]）还没有不装（下方格子最优解）大
            m[i][j]=max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
    }
    // 第1行只算最后一列，单拎出来
    m[1][c]=m[2][c];
    if(c>w[1])
        m[1][c]=max(m[1][c],m[2][c-w[1]]+v[1]);
}

template<typename Type>
void Traceback(Type** m,int* w,int c,int n,int* x){
    for(int i=1;i<n;i++){
        // 如果是从下一行转移上来的，也就是没装，记作0
        if(m[i][c]==m[i+1][c])
            x[i]=0;
        // 如果不是，记作1
        else{
            x[i]=1;
            c-=w[i];
        }
    }
    x[n]=(m[n][c])?1:0;
}

bool PrintMatrix(int **m,int r,int c,int* v,int* w){
    printf("  v  w    ");
    for(int i=0;i<=c;i++)
        printf("%4d",i);
    printf("\n");
    printf("           ");
    for (int i=0;i<=c;i++)
        printf("____");
    printf("\n");
    for (int i=1;i<=r;i++){
        printf("%3d%3d%4d|",v[i],w[i],i);
        for (int j=0;j<=c;j++)
            if(j==w[i])
                printf(" [%2d",m[i][j]);
            else
                printf("%4d",m[i][j]);
        printf("\n");
    }
    return true;
}

int main(){
    const int n=5;
    const int c=10;
    // 写到这里才发现书上对所有一维数组从1开始数的好处，如果频繁在数组“从0起”和矩阵“从1起”间切换确实是一件让人很不舒服的事情
    // 所以以后干脆都从1开始好了，在oj上输入的时候直接i=1配&w[i]或者i=0配&w[i+1]
    // int w[n+1]={0,2,2,6,5,4};
    // int v[n+1]={0,6,3,5,4,6};
    int w[n+1]={0,1,5,4,2,2};
    int v[n+1]={0,4,6,4,3,2};
    int m[n+1][c+1]={0};
    int* pm[n+1];
    for(int i=0;i<(n+1);i++)
        pm[i]=m[i];
    int x[n+1]={0};
    Knapsack(v,w,c,n,pm);
    PrintMatrix(pm,n,c,v,w);
    Traceback(pm,w,c,n,x);
    printf("x=(%d",x[1]);
    for(int i=2;i<=n;i++)
        printf(",%d",x[i]);
    printf(")");
    return 0;
}