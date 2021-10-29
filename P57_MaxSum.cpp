#include <cstdio>

int MaxSum1(int n,int* a,int &besti,int &bestj){//简单算法 O(n^3)
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int thisSum=0;// 每次重新计算从i到j的子段和
            for(int k=i;k<=j;k++)
                thisSum+=a[k];
            if(thisSum>sum){
                sum=thisSum;
                besti=i;
                bestj=j;
            }
        }
    }
    return sum;
}

int MaxSum2(int n,int* a,int &besti,int &bestj){//改进的简单算法 O(n^2)
    int sum=0;
    for(int i=1;i<=n;i++){
        int thisSum=0;// 从i到j的子段和=第j个整数+从i到j-1的子段和（上次对j循环得到的子段和）
        for(int j=i;j<=n;j++){
            thisSum+=a[j];
            if(thisSum>sum){
                sum=thisSum;
                besti=i;
                bestj=j;
            }
        }
    }
    return sum;
}

int MaxSubSum(int *a,int left,int right){
    int sum=0;
    if(left==right)
        return a[left]>0?a[left]:0;
    else{
        int middle=(left+right)/2;
        int leftSubSum=MaxSubSum(a,left,middle);
        int rightSubSum=MaxSubSum(a,middle+1,right);

        int s1=0;
        int thisS1=0;
        for(int i=middle;i>=left;i--){
            thisS1+=a[i];
            if(thisS1>s1)
                s1=thisS1;
        }

        int s2=0;
        int thisS2=0;
        for(int i=middle+1;i<=right;i++){
            thisS2+=a[i];
            if(thisS2>s2)
                s2=thisS2;
        }
        int crossSubSum=s1+s2;
        sum=crossSubSum;
        if(leftSubSum>sum)
            sum=leftSubSum;
        if(rightSubSum>sum)
            sum=rightSubSum;
    }
    return sum;
}

int MaxSum3(int n,int* a){//分治算法 O(nlogn)
    return MaxSubSum(a,1,n);
}

int MaxSum4(int n,int* a){//动态规划算法 O(n)
    int sum=0;
    int b=0;
    // 在变量只从子结构的一种情况转移时可以用一维dp，而且这个状态转移方程只在两个相邻格子之间(b[j-1] b[j])甚至不需要定义数组
    // 二维dp也是一样的，状态转移方程只在两个相邻行之间(dp[i][] dp[i-1][])甚至不需要定义m*n的二维数组，这就是许多题解将空间复杂度O(m*n)优化为O(min(m,n))的依据
    for(int i=1;i<=n;i++){
        if(i==1) printf("b=[");
        printf("%d",b>0 ? b+=a[i] : b=a[i]);// 试了一下赋值语句的返回值，顺便打印过程
        if(i!=n) printf(",");
        // b>0 ? b+=a[i] : b=a[i];
        // 注意该算法的结果取最大值而不是b[n]，要记得打擂保存
        if(b>sum)
            sum=b;
    }
    printf("]");
    return sum;
}


int main(){
    const int n=6;
    int a[n+1]={0,-2,11,-4,13,-5,-2};
    // int besti,bestj;
    // int maxSubSum=MaxSum1(n,a,besti,bestj);
    // int maxSubSum=MaxSum2(n,a,besti,bestj);
    // int maxSubSum=MaxSum3(n,a);
    int maxSubSum=MaxSum4(n,a);
    // printf("(%d,%d)",besti,bestj);
    printf("\n%d",maxSubSum);
    return 0;
}