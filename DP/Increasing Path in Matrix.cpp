// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/increasing-path-in-matrix/
// Easy

/*
Problem Description
Given a 2D integer matrix A of size N x M.
From A[i][j] you can move to A[i+1][j], if A[i+1][j] > A[i][j], or can move to A[i][j+1] if A[i][j+1] > A[i][j].
The task is to find and output the longest path length if we start from (0, 0).

NOTE:
If there doesn't exist a path return -1.

Problem Constraints
1 <= N, M <= 10^3
1 <= A[i][j] <= 10^8

Input Format
First and only argument is an 2D integer matrix A of size N x M.

Output Format
Return a single integer denoting the length of longest path in the matrix if no such path exists return -1.

Example Input
Input 1:
 A = [  [1, 2]
        [3, 4]
     ]

Input 2:
 A = [  [1, 2, 3, 4]
        [2, 2, 3, 4]
        [3, 2, 3, 4]
        [4, 5, 6, 7]
     ]

Example Output
Output 1:
 3

Output 2:
 7

Example Explanation
Explanation 1:
 Longest path is either 1 2 4 or 1 3 4.

Explanation 2:
 Longest path is 1 2 3 4 5 6 7.
*/


// There is nothing like longest path. 
// We have to check if there exists path between (0,0) -> (n-1, m-1) with given conditions

int n, m;
int dp[1001][1001];

int rec(int x, int y, vector<vector<int> > &mat)
{
    if(x == n-1 && y == m-1)
        return 1;
    
    if(dp[x][y] != -1)
        return dp[x][y];
    
    int ans = -1;
    if(x == n-1)
    {
        if(mat[x][y+1] > mat[x][y])
        {
            int next = rec(x, y+1, mat);
            if(next != -1)
                ans = next+1;
        }
        return dp[x][y] = ans;
    }
    
    if(y == m-1)
    {
        if(mat[x+1][y] > mat[x][y])
        {
            int next = rec(x+1, y, mat);
            if(next != -1)
                ans = 1+next;
        }
        return dp[x][y] = ans;
    }
    
    if(mat[x][y+1] > mat[x][y])
    {
        int next = rec(x, y+1, mat);
        if(next != -1)
            ans = 1+next;
    }
    if(mat[x+1][y] > mat[x][y])
    {
        int next = rec(x+1, y, mat);
        if(next != -1)
            ans = 1+next;
    }
    return dp[x][y] = ans;
}

int Solution::solve(vector<vector<int> > &A) 
{
    memset(dp, -1, sizeof(dp));
    n = A.size(), m = A[0].size();
    return rec(0, 0, A);
}
