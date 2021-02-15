// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/paint-house/
// easy one

int Solution::solve(vector<vector<int> > &A) 
{
    int n = A.size();
    int dp[n][3];
    dp[0][0] = A[0][0];
    dp[0][1] = A[0][1];
    dp[0][2] = A[0][2];
    
    for(int i = 1; i < n; ++i)
    {
        dp[i][0] = A[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = A[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = A[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }
    return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
}

// Can be done in O(1) space complexity
// just store previous 3 values dp[i-1][0], dp[i-1][1], dp[i-1][2] in an array and update it in each iteration

int Solution::solve(vector<vector<int> > &A) 
{
    int n = A.size(), t1, t2, t3;
    int dp[3];
    dp[0] = A[0][0];
    dp[1] = A[0][1];
    dp[2] = A[0][2];
    
    for(int i = 1; i < n; ++i)
    {
        t1 = dp[0];
        t2 = dp[1];
        t3 = dp[2];
        dp[0] = A[i][0] + min(t2, t3);
        dp[1] = A[i][1] + min(t1, t3);
        dp[2] = A[i][2] + min(t1, t2);
    }
    return min(dp[0], min(dp[1], dp[2]));
}
