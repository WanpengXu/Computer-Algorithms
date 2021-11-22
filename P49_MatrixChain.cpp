#include <cstdio>
void MatrixChain(int *p,int n,int **m,int **s){
    for (int i=1;i<=n;i++)
        m[i][i]=0;
    for (int r=2;r<=n;r++){
        for (int i=1;i<=n-r+1;i++){
            int j=i+r-1;
            // 打擂法初始化
            int k=i;
            m[i][j]=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];//m[i][i]=0，所以可以不写
            s[i][j]=i;
            for (int k=i+1;k<j;k++){
                int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if (t<m[i][j]){
                    m[i][j]=t;
                    s[i][j]=k;
                }
            }
        }
    }
}
bool Traceback(int i,int j,int **s){
    if (i==j)
        return false;
    Traceback(i,s[i][j],s);
    Traceback(s[i][j]+1,j,s);
    printf("Multiply A %d, %d and A %d, %d\n",i,s[i][j],s[i][j]+1,j);
    return true;
}
bool PrintMatrixFromOne(int **m,int r,int c){
    // int r=sizeof(m)/sizeof(m[0]);
    // int c=sizeof(m[0])/sizeof(m[0][0]);
    for (int i=1;i<r+1;i++){
        for (int j=1;j<c+1;j++)
            printf("%8d ",m[i][j]);
        printf("\n");
    }
    printf("\n");
    return true;
}
int main(){
    // const int n=6;
    // int p[n+1]={30,35,15,5,10,20,25};
    const int n=5;
    int p[n+1]={20,30,50,10,35,25};
    // int p[n+1]={4,6,10,2,7,5};
    // m和n忽略0行0列
    int m[n+1][n+1]={};
    int *pm[n+1];
    for (int i=1;i<=n+1;i++)
        pm[i]=m[i];
    int s[n+1][n+1]={};
    int *ps[n+1];
    for (int i=1;i<=n+1;i++)
        ps[i]=s[i];
    MatrixChain(p,n,pm,ps);
    PrintMatrixFromOne(pm,n,n);
    PrintMatrixFromOne(ps,n,n);
    Traceback(1,n,ps);
    return 0;
}