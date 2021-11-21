#include <cstdio>
#include <algorithm>
using namespace std;

template <typename Type>
int Split(Type a[],int p,int r){
    int i=p;
    Type x=a[p];
    for(int j=p+1;j<=r;j++)
        if(x>a[j] && ++i!=j)
                swap(a[i],a[j]);
    // swap(a[i],a[p]);  // 标准的Split算法
    // 模拟手算的Split算法
    for(int j=p;j<i;j++)
        swap(a[j],a[j+1]);
    return i;
}

template <typename Type>
void QuickSort(Type a[],int p,int r){
    if(p<r){
        printf("Spliting: {%d",a[p]);
        for(int i=p+1;i<=r;i++)
            printf(",%d",a[i]);
        printf("}\n");

        int q=Split(a,p,r);

        printf("Splited:  {%d",a[p]);
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