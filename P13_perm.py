from typing import List

def perm(ls:List,k:int,m:int)->None:
    if k==m:
        for i in range(m+1):
            print(ls[i],end='')
        print()
    else:
        for i in range(k,m+1):
            ls[k],ls[i]=ls[i],ls[k]
            perm(ls,k+1,m)
            ls[k],ls[i]=ls[i],ls[k]

def main():
    ls=[1,2,3]
    perm(ls,0,2)

if __name__=="__main__":
    main()
