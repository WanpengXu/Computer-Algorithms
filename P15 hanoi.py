from typing import List

def move(a:List,b:List)->None:
    temp=a.pop()
    b.append(temp)

def hanoi(n:int,a:List,b:List,c:List)->None:#para3：借用柱
    if n>0:
        hanoi(n-1,a,c,b)
        move(a,b)
        globalPrint()
        hanoi(n-1,c,b,a)

a,b,c=[],[],[]

def globalPrint():
    print(a,b,c)

def main():
    n=3
    for i in range(n,0,-1):
        a.append(i)
    hanoi(n,a,b,c)

if __name__=="__main__":
    main()