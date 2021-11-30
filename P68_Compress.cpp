#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int BitLength(int i){
    int k=1;
    i/=2;
    while(i>0){
        k++;
        i/=2;
    }
    return k;
}

void Compress(int n,int p[],int s[],int l[],int b[]){
    int Lmax=256,header=11;
    s[0]=0;
    for(int i=1;i<=n;i++){
        b[i]=BitLength(p[i]);
        int bmax=b[i];
        s[i]=s[i-1]+bmax;
        l[i]=1;
        for(int k=2;k<=i&&k<=Lmax;k++){
            if(bmax<b[i-k+1])
                bmax=b[i-k+1];
            if(s[i]>s[i-k]+k*bmax){
                s[i]=s[i-k]+k*bmax;
                l[i]=k;
            }
        }
        s[i]+=header;
    }
}

void Traceback(int n,int& i,int s[],int l[]){
    if(n==0)
        return ;
    Traceback(n-l[n],i,s,l);
    s[i++]=n-l[n];
}

void Output(int s[],int l[],int b[],int n){
    cout<<"The optimal value is "<<s[n]<<endl;
    int m=0;
    Traceback(n,m,s,l);
    s[m]=n;

    cout<<"Decompose into "<<m<<" segments "<<endl;
    for(int j=1;j<=m;j++){
        l[j]=l[s[j]];
        for(int k=s[j-1];k<=s[j];k++)  // 这里应该取整段的最大bit值而不是取最后一个
            b[j]=max(b[j],b[k]);
    }
    for(int j=1;j<=m;j++)
        cout<<"Segment"<<j<<": "<<"length is "<<l[j]<<", "<<"bits is "<<b[j]<<endl;
}

void printVector(int* x,int n){
    for(int i=1;i<=n;i++)
        printf("%5d",x[i]);
    printf("\n");
}

int main(){
    const int n=9;
    int* p=new int[n+1]{0,9,11,10,12,15,127,178,220,0};
    // const int n=7;
    // int* p=new int[n+1]{0,4,5,6,7,129,138,1};
    int* b=new int[n+1]();  // 使用()将每个元素初始化为0
    int* l=new int[n+1]();
    int* s=new int[n+1]();
    Compress(n,p,s,l,b);

    printf("   i   ");
    for(int i=1;i<=n;i++)
        printf("%5d",i);
    printf("\n       ");
    for(int i=1;i<=n;i++)
        printf("_____");
    printf("\n");
    printf(" p[i] |");
    printVector(p,n);
    printf(" b[i] |");
    printVector(b,n);
    printf(" l[i] |");
    printVector(l,n);
    printf(" s[i] |");
    printVector(s,n);
    printf("\n");

    Output(s,l,b,n);

    return 0;
}