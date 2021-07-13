// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/n-digit-numbers-with-digit-sum-s-/
// Easy

/*
Find out the number of N digit numbers, whose digits on being added equals to a given number S. Note that a valid number starts from digits 1-9 except 
the number 0 itself. i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007

N = 2, S = 4
Valid numbers are {22, 31, 13, 40}
Hence output 4.
*/

#define ll long long

const long long MOD = 1000000007;
vector<vector<ll> > dp;

ll rec(int n, int s)
{
    if(n == 0 && s == 0) // valid number found
        return 1;
    
    if(n == 0 || s < 0) // number cant be formed
        return 0;
    
    if(dp[n][s] != -1)
        return dp[n][s];
    
    ll ans = 0;
    for(int i = 0; i <= 9; ++i)
        ans = (ans + rec(n-1, s-i)) % MOD;
    
    return dp[n][s] = ans;
}

int Solution::solve(int n, int s) 
{
    dp = vector<vector<ll> >(n+1, vector<ll>(s+1, -1));
    ll ans = 0;
    for(int i = 1; i <= 9; ++i)
        ans = (ans + rec(n-1, s-i)) % MOD;
    
    return ans;
}
