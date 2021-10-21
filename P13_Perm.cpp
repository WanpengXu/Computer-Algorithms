#include <iostream>
using namespace std;

void Perm(int list[],int k,int m){
    if(k==m){
        for(int i=0;i<=m;i++)
            cout<<list[i];
    cout<<endl;
    }
    else{
        for(int i=k;i<=m;i++){
            swap(list[k],list[i]);
            Perm(list,k+1,m);
            swap(list[k],list[i]);
        }
    }
}

int main(){
    int s[]={1,2,3};
    int length=sizeof(s)/sizeof(s[0]);
    Perm(s,0,length-1);
    return 0;
}