#include <cstdio>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

template <typename Type>
Type Random(Type p,Type r){
    random_device rd;
    default_random_engine e(rd());
    uniform_int_distribution<Type> u(p, r);
    Type x=u(e);
    return x;
}

template <typename Type>
int Partition(Type a[],int p,int r){
    int i=p,j=r+1;
    while(true){
        while(a[++i]<a[p] && i<r)
            ;
        while(a[--j]>a[p])
            ;
        if(i>=j)
            break;
        swap(a[i],a[j]);
    }
    swap(a[p],a[j]);
    return j;
}

template <typename Type>
int RandomizedPartition(Type a[],int p,int r){
    int i=Random(p,r);
    swap(a[i],a[p]);
    return Partition(a,p,r);
}

template <typename Type>
void RandomizedQuickSort(Type a[],int p,int r){
    if(p<r){
        printf("Sorting: {%d",a[p]);
        for(int i=p+1;i<=r;i++)
            printf(",%d",a[i]);
        printf("}\n");
        
        int q=RandomizedPartition(a,p,r);

        printf("Sorted:  {%d",a[p]);
        for(int i=p+1;i<=r;i++)
            printf(",%d",a[i]);
        printf("}\n");

        RandomizedQuickSort(a,p,q-1);
        RandomizedQuickSort(a,q+1,r);
    }
}

template <typename Type>
void RandomizedQuickSort(vector<Type>& a,int p,int r){
    // 将向量转为数组
    int arr[a.size()];
    copy(a.begin(),a.end(),arr);
    // 调用数组的随机化的快速排序算法
    RandomizedQuickSort(arr,p,r);
    // 将排序后的数组转为向量
    vector<int> varr(arr, arr+a.size());  // 拷贝指针的范围左闭右开，arr+a.size()是已知数组长度（原向量长度）的做法，数组长度大多数时候需要计算，即结束指针使用arr+sizeof(arr)/sizeof(arr[0])
    // 赋值回向量
    a=varr;
}

int main(){
    const int n=8;
    vector<int> a={0,8,4,1,7,11,5,6,9};  // C++98 STL
    // int *a=new int[n+1]{0,8,4,1,7,11,5,6,9};  // C++11
    // int a[n+1]={0,8,4,1,7,11,5,6,9};  // C99

    printf("Original a={%d",a[1]);
    for(int i=2;i<=n;i++)
        printf(",%d",a[i]);
    printf("}\n\n");

    RandomizedQuickSort(a,1,n);

    printf("\nResult a={%d",a[1]);
    for(int i=2;i<=n;i++)
        printf(",%d",a[i]);
    printf("}");

    return 0;
}
