# O(n^2) LIS

def LIS(l):
    """Return the lenght of Longest Increasing Subsequence in l"""
    dp = [1 for _ in range(len(l))] #dp[i]: lenght of LIS containing l[i] as its last element

    for i in range(len(l)):
        for j in range(i):
            if(l[j]<l[i]):
                dp[i] = max(dp[i],dp[j]+1)

    return max(dp)
