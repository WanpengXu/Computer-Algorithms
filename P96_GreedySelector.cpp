#include <cstdio>
// #include <cstring>
#include <algorithm>
using namespace std;
// 不直接对数组排序，而是按排序标准对下标排序，这样可以达到同时排序多个数组的效果（保留数组间原本的同下标映射关系）
// int arr[5]=    {   4,   1,   3,   6,   2};
// string arr1[5]={"a1","b1","c1","d1","e1"};

// int indices[5]={0,1,2,3,4};
// sort(indices, indices+5, SortIndices(arr));
// int indices[5]={1,4,2,0,3}; //排序完应该是这样的

// arr[indices[i]]与arr1[indices[i]]仍有映射关系

class SortIndices{
private:
    int* mparr;
public:
    SortIndices(int* parr)
    :mparr(parr)
    {}
    bool operator()(int i,int j)const{
        return mparr[i]<mparr[j];
    }
};

void GreedySelector(int n,int s[],int f[],bool A[],int indices[]){
    // @param s start 
    // @param t final
    A[1]=true;
    int j=1;// 正进行的活动
    for(int i=2;i<=n;i++){
        if(f[indices[j]]<=s[indices[i]]){//if(f[j]<=s[i]){
            A[i]=true;
            j=i;
        }
        else
            A[i]=false;
    }
}
int main(){
    const int N=11;
    // int s[N+1]={0,1,3,0,5,3,5,6,8,8,2,12};
    // int f[N+1]={0,4,5,6,7,8,9,10,11,12,13,14};
    int s[N+1]={0,5,0,3,5,3,1,8,6,8,12,2};
    int f[N+1]={0,9,6,5,7,8,4,11,10,12,14,13};
    bool A[N+1]={false};
    // memset(A,false,sizeof(A[0]));

    int indices[N+1]={0,1,2,3,4,5,6,7,8,9,10,11};
    sort(indices+1, indices+N+1, SortIndices(f));

    printf("i    |");
    for(int i=1;i<=N;i++)
        printf("%4d",indices[i]);
    printf("\n");

    printf("s[i] |");
    for(int i=1;i<=N;i++)
        printf("%4d",s[indices[i]]);
    printf("\n");

    printf("f[i] |");
    for(int i=1;i<=N;i++)
        printf("%4d",f[indices[i]]);
    printf("\n");

    GreedySelector(N,s,f,A,indices);

    printf("A[i] |");
    for(int i=1;i<=N;i++)
        printf("%4d",A[i]);
    printf("\n");

    printf("E={%d",indices[1]);  // 第一个活动必被选中
    for(int i=2;i<=N;i++)
        if(A[i]==true)
            printf(",%d",indices[i]);
    printf("}");
    return 0;
}