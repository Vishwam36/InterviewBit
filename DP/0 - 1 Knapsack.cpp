// By Vishwam Shriram Mundada
// 
// Very Important

// Top-Down approach
int Solution::solve(vector<int> &A, vector<int> &B, int C) 
{
    int n = A.size();
    int dp[C+1][n+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i <= C; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(B[j-1] <= i)
                dp[i][j] = max(A[j-1] + dp[i-B[j-1]][j-1], dp[i][j-1]);
            
            else
                dp[i][j] = dp[i][j-1];
        }
    }
    return dp[C][n];
}


// This is recursion + memoization. But this is partially accepted on InterviewBit.
/*
int dp[1001][1001];

int knapsack(vector<int> A, vector<int> B, int C, int N)
{
    if(N <= 0 || C <= 0)
        return 0;
        
    if(dp[C][N] != -1)
        return dp[C][N];
        
    if(B[N-1] <= C)
    {
        dp[C][N] = max(A[N-1] + knapsack(A, B, C - B[N-1], N-1),
                        knapsack(A, B, C, N-1));
    }
    else
    {
        dp[C][N] = knapsack(A, B, C, N-1);
    }
    return dp[C][N];
}

int Solution::solve(vector<int> &A, vector<int> &B, int C) 
{
    memset(dp, -1, sizeof(dp));
    return knapsack(A, B, C, A.size());
}
*/
