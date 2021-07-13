// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/maximum-path-in-triangle/
// Easy

/*
Problem Description
Given a 2D integer array A of size N * N representing a triangle of numbers.
Find the maximum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

NOTE:
    Adjacent cells to cell (i,j) are only (i+1,j) and (i+1,j+1)
    Row i contains i integer and n-i zeroes for all i in [1,n] where zeroes represents empty cells.

Problem Constraints
0 <= N <= 1000
0 <= A[i][j] <= 1000

Input Format
First and only argument is an 2D integer array A of size N * N.

Output Format
Return a single integer denoting the maximum path sum from top to bottom in the triangle.

Example Input
Input 1:
 A = [
        [3, 0, 0, 0]
        [7, 4, 0, 0]
        [2, 4, 6, 0]
        [8, 5, 9, 3]
     ]

Input 2:
 A = [
        [8, 0, 0, 0]
        [4, 4, 0, 0]
        [2, 2, 6, 0]
        [1, 1, 1, 1]
     ]

Example Output
Output 1:
 23

Output 2:
 19

Example Explanation
Explanation 1:
 Given triangle looks like:  3
                             7 4
                             2 4 6
                             8 5 9 3
        So max path is (3 + 7 + 4 + 9) = 23

Explanation 1:
 Given triangle looks like:  8
                             4 4
                             2 2 6
                             1 1 1 1
        So max path is (8 + 4 + 6 + 1) = 19
*/

// App 1 : Recursion + Memoization
// Will give TLE for some test cases

int n;
vector<vector<int> > dp;

int rec(int row, int col, vector<vector<int> > &mat)
{
    if(row == n)
        return 0;
    
    if(dp[row][col] != -1)
        return dp[row][col];
    
    return max(rec(row+1, col, mat), rec(row+1, col+1, mat)) + mat[row][col];
}

int Solution::solve(vector<vector<int> > &A) 
{
    n = A.size();
    dp = vector<vector<int> >(n, vector<int>(n, -1));
    return rec(0, 0, A);
}


// App 2 : Bottom Up
// Full passed

int Solution::solve(vector<vector<int> > &mat)
{
    int n = mat.size();
    
    for(int i = 1; i < n; ++i)
        for(int j = 0; j <= i; ++j)
            mat[i][j] += max(mat[i-1][j], (j-1 >= 0 ? mat[i-1][j-1] : INT_MIN));
    
    return *max_element(mat[n-1].begin(), mat[n-1].end());
}
