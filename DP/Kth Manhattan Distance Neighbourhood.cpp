// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/kth-manhattan-distance-neighbourhood/
// Decent

/*
Given a matrix M of size nxm and an integer K, find the maximum element in the K manhattan distance neighbourhood for all elements in nxm matrix.
In other words, for every element M[i][j] find the maximum element M[p][q] such that abs(i-p)+abs(j-q) <= K.

Note: Expected time complexity is O(N*N*K)

Constraints:
1 <= n <= 300
1 <= m <= 300
1 <= K <= 300
0 <= M[i][j] <= 1000
Example:

Input:
M  = [[1,2,4],[4,5,8]] , K = 2

Output:
ans = [[5,8,8],[8,8,8]]
*/

vector<vector<int> > Solution::solve(int k, vector<vector<int> > &mat) 
{
    int n = mat.size(), m = mat[0].size();
    vector<vector<int> > dp = mat, tempDP;
    while(k--)
    {
        tempDP = dp;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(i > 0)
                    tempDP[i][j] = max(tempDP[i][j], dp[i-1][j]);
                if(j > 0)
                    tempDP[i][j] = max(tempDP[i][j], dp[i][j-1]);
                if(i < n-1)
                    tempDP[i][j] = max(tempDP[i][j], dp[i+1][j]);
                if(j < m-1)
                    tempDP[i][j] = max(tempDP[i][j], dp[i][j+1]);
            }
        }
        dp = tempDP;
    }
    return dp;
}
