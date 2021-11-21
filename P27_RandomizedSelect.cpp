#include <cstdio>
#include <random>
#include <algorithm>
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
        int q=RandomizedPartition(a,p,r);
        RandomizedQuickSort(a,p,q-1);
        RandomizedQuickSort(a,q+1,r);
    }
}

template <typename Type>
Type RandomizedSelect(Type a[],int p,int r,int k){
    if(p==r)
        return a[p];
    int i=RandomizedPartition(a,p,r);
    int j=i-p+1;
    if(k<=j)
        return RandomizedSelect(a,p,i,k);
    else
        return RandomizedSelect(a,i+1,r,k-j);
}

int main(){
    const int n=22;
    int k=5;  // k在一些情况下会导致随机数引擎段错误，很迷啊席八，换C里面的rand()也一样，考完试再想（估计不会了）
    int* a=new int [n+1]{0,2,6,9,1,4,10,20,6,22,11,10,9,4,3,7,16,11,8,2,5,4,1};
    int ak=RandomizedSelect(a,1,n,k);
    RandomizedQuickSort(a,1,n);

    printf("a[i]|");
    for(int i=1;i<=n;i++)
        printf("%3d",a[i]);
    printf("\n");

    printf("  i |");
    for(int i=1;i<=n;i++)
        printf("%3d",i);
    printf("\n");

    printf("The %d-th smallest element is %d",k,ak);
    return 0;
}