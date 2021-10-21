def q(n:int,m:int)->int:
    if n<1 or m<1:
        return 0
    if n==1 or m==1:
        return 1
    if n<m:
        return q(n,n)
    if n==m:
        return q(n,m-1)+1
    return q(n,m-1)+q(n-m,m)

def p(n:int)->int:
    return q(n,n)

def main():
    x=6
    print(p(x))

if __name__=="__main__":
    main()