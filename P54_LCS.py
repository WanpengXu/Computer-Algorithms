def lcs_length(text1:str,text2:str)->int:
    m,n=len(text1),len(text2)
    dp=[[0]*(n+1) for _ in range(m+1)]
    for i in range(1,m+1):
        for j in range(1,n+1):
            if text1[i-1]==text2[j-1]:
                dp[i][j]=dp[i-1][j-1]+1
            else:
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])
                # 输出跟CUMT式先上后左的答案不同的原因在于这个max
    return dp[-1][-1]#逆序下标，代表最后一行最后一列，即dp[m][n]

def main():
    A='abcbdb'
    B='acbbabdbb'
    print(lcs_length(A,B))

if __name__=="__main__":
    main()