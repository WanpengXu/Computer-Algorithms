#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
void LCSLength(int m,int n,char *x,char *y,int **c,int **b){
    int i,j;
    // 这里要改，不然c[0][0]初始化不到，其实为了完整性（好看）b也该初始化的
    // 初始化第0列
    for(int i=0;i<=m;i++)
        c[i][0]=0;
    // 初始化第0行
    for(int i=0;i<=n;i++)
        c[0][i]=0;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
        // 从左到右 从上到下遍历
            // 对一个4格的右下格子
            // 如果匹配上了，从左上格子转移
            // 这里要改，串的索引应从0起
            if(x[i-1]==y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
            // 如果没匹配上
            // 且上方格子大于（等于）左方格子，从上方格子转移
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }
            // 且左方格子大于上方格子，从左方格子转移
            else{
                c[i][j]=c[i][j-1];
                b[i][j]=3;
            }
        }
    }
}

void LCS(int i,int j,char *x,int **b){
    // 如果递归至边界，结束
    if(i==0||j==0)
        return ;
    // 如果标记为1（左上箭头），递归进左上格子，递归结束后打印本格字符
    if(b[i][j]==1){
        LCS(i-1,j-1,x,b);
        // 这里要改，串的索引应从0起
        cout<<x[i-1];
    }
    // 如果标记为2（向上箭头），递归进上方格子，不打印
    else if(b[i][j]==2)
        LCS(i-1,j,x,b);
    // 如果标记为3（向左箭头），递归进左方格子，不打印
    else 
        LCS(i,j-1,x,b);
}

bool PrintMatrix(int **m,int r,int c,char *x,char *y){
    printf("        \'\'");
    for (int i=0;i<=c;i++)
        printf("%8c",y[i]);
    printf("\n");
    for (int i=0;i<=r;i++){
        if(i==0)
            printf("\'\'");
        else
            printf("%2c",x[i-1]);
        for (int j=0;j<=c;j++)
            printf("%8d",m[i][j]);
        printf("\n");
    }
    printf("\n");
    return true;
}

int main(){
    char A[]="abcbdb";
    char B[]="acbbabdbb";
    const int lenA=strlen(A);
    const int lenB=strlen(B);
    // 法一：直接创建指针的指针（创建int*的指针int**）
    int** c=new int*[lenA+1];//先创建指针的指针，指向一个指针数组
    for (int i=0;i<lenA+1;i++)
        c[i]=new int[lenB+1];//让指针数组中的每一个指针，都指向一个动态一维数组
    int** b=new int*[lenA+1];
	for (int i=0;i<lenA+1;i++)
		b[i]=new int[lenB+1];
    // b[0][2]=3;int**可以用[]运算符赋值
    LCSLength(lenA,lenB,A,B,c,b);
    LCS(lenA,lenB,A,b);
    printf("\n%d",c[lenA][lenB]);
    printf("\n");
    PrintMatrix(c,lenA,lenB,A,B);

    // 行指针int(*)[col]演示
    // int a[3][3]={
    // {1,2,3},
    // {4,5,6},
    // {7,8,9}};
    // cout<<endl<<**a<<endl<<**(a+1)<<endl<<**(a+2);

    // 法二：将“行指针”的指针转化为指针的指针
    // int c[lenA+1][lenB+1]={0},b[lenA+1][lenB+1]={0};
    // int *pc[lenA+1],*pb[lenA+1];
    // for(int i=0;i<lenA+1;i++){
    // 把每个行指针转化为指针（将int(*)[col]转为int*）
    //     pc[i]=c[i];
    //     pb[i]=b[i];
    // }
    // LCSLength(lenA,lenB,A,B,pc,pb);
    // LCS(lenA,lenB,A,pb);
    return 0;
}