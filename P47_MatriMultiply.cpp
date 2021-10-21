#include <cstdio>
#include <cstdlib>
bool MatriMultiply(int **a,int **b,int **c,int ra,int ca,int rb,int cb){
    if(ca!=rb){
        perror("矩阵不可乘");
        exit(EXIT_FAILURE);// #define EXIT_FAILURE 1
    }
    for(int i=0;i<ra;i++){
        for(int j=0;j<cb;j++){
            int sum=a[i][0]*b[0][j];
            for(int k=1;k<ca;k++)
                sum+=a[i][k]*b[k][j];
            c[i][j]=sum;
        }
    }
    return true;
}
int main(){
    int a[3][3]={
    {1,2,1},
    {1,2,1},
    {1,2,1}};
    int ra=3;
    int ca=3;
    int *pa[3];
    for(int i=0;i<ra;i++)
        pa[i]=a[i];

    int b[3][3]={
    {2,1,1},
    {2,1,1},
    {2,1,1}};
    int rb=4;
    int cb=3;
    int *pb[3];
    for(int i=0;i<rb;i++)
        pb[i]=b[i];

    int c[3][3]={{},{},{}};
    int rc=3;
    int cc=3;
    int *pc[3];
    for(int i=0;i<rc;i++)
        pc[i]=c[i];

    MatriMultiply(pa,pb,pc,ra,ca,rb,cb);
    for(int i=0;i<rc;i++){
        for(int j=0;j<cc;j++)
            printf("%d ",c[i][j]);
        printf("\n");
    }
    return 0;
}