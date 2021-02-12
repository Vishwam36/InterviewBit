// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/longest-palindromic-subsequence/
// decent, similar to longest common subsequence

int dp[1010][1010];

int lps(string A, int i, int j)
{
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(i == j)
        dp[i][j] = 1;
    
    else if(A[i] == A[j] && i+1 == j)
        dp[i][j] = 2;
        
    else if(A[i] == A[j])
        dp[i][j] = 2 + lps(A, i+1, j-1);
        
    else
        dp[i][j] = max(lps(A, i, j-1), lps(A, i+1, j));
        
    return dp[i][j];
}

int Solution::solve(string A) 
{
    memset(dp, -1, sizeof(dp));
    return lps(A, 0, A.size()-1);
}
