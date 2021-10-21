#include <stack>
#include <iostream>
//#define VNAME(value) (#value)
using namespace std;


void Move(stack<int> &a,stack<int> &b){
    b.push(a.top());
    a.pop();
    return ;
}

void Hanoi(int n,stack<int> &a,stack<int> &b,stack<int> &c){
    if(n>0){
        Hanoi(n-1,a,c,b);
        Move(a,b);
        Hanoi(n-1,c,b,a);
    }
    return ;
}

void StackPrint(stack<int> s){
    //cout<<VNAME(s)<<':';
    for (stack<int> dump=s;!dump.empty();dump.pop())
        cout<<dump.top()<<' ';
    cout<<'\n';
}

int main(){
    stack<int> a,b,c;
    int n=3;
    for(int i=n;i>0;i--)
        a.push(i);

    cout<<"a:";
    StackPrint(a);
    cout<<"b:";
    StackPrint(b);
    cout<<"c";
    StackPrint(c);
    
    Hanoi(n,a,b,c);
    cout<<"a:";
    StackPrint(a);
    cout<<"b:";
    StackPrint(b);
    cout<<"c";
    StackPrint(c);
    return 0;
}