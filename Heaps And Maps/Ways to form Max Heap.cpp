// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/ways-to-form-max-heap/
// Good question
// Combination of DP and concept of heaps
// Ref : https://www.geeksforgeeks.org/number-ways-form-heap-n-distinct-integers/

#define MOD 1000000007
#define MAXN 105

long long nck[MAXN][MAXN];
long long dp[MAXN];

long long combination(int n, int k)
{
    if(k > n)
        return 0;
        
    if(n <= 1)
        return 1;
        
    if(k == 0)
        return 1;
        
    if(nck[n][k] != -1)
        return nck[n][k];
        
    nck[n][k] = combination(n-1, k-1) + combination(n-1, k);
    
    return nck[n][k] % MOD;
}

long long ways(int n)
{
    if(n <= 2)
        return 1;
    
    if(dp[n] != -1)
        return dp[n];
        
    int h = log2(n), l = 0;
    int lastRow = n - ((1 << h) - 1);
    int filledLastRow = (1 << h);
    
    if(lastRow >= filledLastRow/2)
        l = (1 << h) - 1;
    
    else
        l = (1 << h) - 1 - (filledLastRow/2 - lastRow);
    
    int r = n - l - 1;
    
    dp[n] = ((combination(n-1,l) * ways(l)) % MOD) * ways(r);
    dp[n] %= MOD;
    
    return dp[n];
}

int Solution::solve(int A) 
{
    memset(nck, -1, sizeof(nck));
    memset(dp, -1, sizeof(dp));
    long long ans = 0;
    ans = ways(A) % MOD;
    return ans;
}
