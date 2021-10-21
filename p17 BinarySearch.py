from typing import List

def BinarySearch(a:List,x,n:int)->int:
    left,right=0,n-1
    while left<=right:
        middle=(left+right)>>1
        if x==a[middle]:
            return middle
        if x>a[middle]:
            left=middle+1
        else:
            right=middle-1
    return -1

def main():
    ls=sorted([1,4,6,2,36,71,6,3,6,8,4,456])
    print(ls)
    print(BinarySearch(ls,36,len(ls)))

if __name__=="__main__":
    main()