#include <cstdio>
#include <algorithm>
using namespace std;

template <typename Type>
int Partition(Type a[],int p,int r){
    int i=p,j=r+1;  // 待排区间[p+1,r]
    Type x=a[p];  // 基准元素
    while(true){
        while(a[++i]<x && i<r)  // 存在a[t]>=x,t=i+1,i+2,...,r-1（后面所有的元素都比基准元素大）的情况，可能越界，即脱离待排数组，需要约束该向右指针以防该情况发生，出于效率我认为可以改做i<j(上一个j)
            ;
        while(a[--j]>x)  // 左侧必定存在元素<=x，不会越界
            ;
        if(i>=j)
            break;
        swap(a[i],a[j]);
    }
    // swap(a[p],a[j]);
    a[p]=a[j];
    a[j]=x;
    return j;
}

template <typename Type>
void QuickSort(Type a[],int p,int r){
    if(p<r){
        printf("Sorting: {%d",a[p]);
        for(int i=p+1;i<=r;i++)
            printf(",%d",a[i]);
        printf("}\n");

        int q=Partition(a,p,r);

        printf("Sorted:  {%d",a[p]);
        for(int i=p+1;i<=r;i++)
            printf(",%d",a[i]);
        printf("}\n");

        QuickSort(a,p,q-1);
        QuickSort(a,q+1,r);
    }
}

int main(){
    const int n=8;
    int *a=new int[n+1]{0,8,4,1,7,11,5,6,9};  // C++11
    // int a[n+1]={0,8,4,1,7,11,5,6,9};  // C99
    
    printf("Original a={%d",a[1]);
    for(int i=2;i<=n;i++)
        printf(",%d",a[i]);
    printf("}\n\n");

    QuickSort(a,1,n);

    printf("\nResult a={%d",a[1]);
    for(int i=2;i<=n;i++)
        printf(",%d",a[i]);
    printf("}");

    return 0;
}
