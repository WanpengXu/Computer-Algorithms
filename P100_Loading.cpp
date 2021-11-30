#include <cstdio>
#include <algorithm>
using namespace std;

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

template<typename Type>// 使用模板以支持整型及浮点型
int* Loading(int x[],Type w[],Type c,int n){
    int *t=new int [n+1];
    for(int i=1;i<=n;i++)
        t[i]=i;
    sort(t+1,t+n+1,SortIndices(w));// 左闭右开,排序范围等价于[t+1,t+n]
    for(int i=1;i<=n;i++)
        x[i]=0;
    for(int i=1;i<=n && w[t[i]]<=c;i++){
        x[t[i]]=1;
        c-=w[t[i]];
    }
    return t;
}

int main(){
    const int n=8;
    int x[n+1];
    int w[n+1]={0,100,200,50,90,150,50,20,80};
    int c=400;

    int* t=Loading(x,w,c,n);


    printf("%-8c|",'i');
    for(int i=1;i<=n;i++)
        printf("%6d",i);
    printf("\n");

    printf("w[t[i]] |");
    for(int i=1;i<=n;i++)
        printf("%6d",t[i]);
    printf("\n");

    printf("loaded  |");
    int loaded=0;
    for(int i=1;i<=n && x[t[i]]==1;i++){
        loaded+=w[t[i]];
        printf("%6d",loaded);
    }
    printf("\n");

    printf("\nx=(%d",x[1]);
    for(int i=2;i<=n;i++)
        printf(",%d",x[i]);
    printf(")");
    return 0;
}