// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/unique-paths-in-a-grid/
// Easy

/*
Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), 
you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example :
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is 2.

    Note: m and n will be at most 100. 
*/

int n, m;
int dp[101][101];

int rec(int i, int j, vector<vector<int> > &mat)
{
    if(i >= n || j >= m || mat[i][j] == 1) // invalid location
        return 0;
    if(i == n-1 && j == m-1) // destination
        return 1;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    return dp[i][j] = rec(i+1, j, mat) + rec(i, j+1, mat);
}

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) 
{
    memset(dp, -1, sizeof(dp));
    n = A.size(), m = A[0].size();
    return rec(0, 0, A);
}
