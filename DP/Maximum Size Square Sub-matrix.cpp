// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/maximum-size-square-sub-matrix/
// Decent

/*
Problem Description
Given a 2D binary matrix A of size  N x M  find the area of maximum size square sub-matrix with all 1's.

Problem Constraints
1 <= N, M <= 103
A[i][j] = 1 or A[i][j] = 0

Input Format
First argument is an 2D matrix A of size N x M.

Output Format
Output the area of maximum size square sub-matrix in A with all 1's.

Example Input
Input 1:
 A = [
        [0, 1, 1, 0, 1],
        [1, 1, 0, 1, 0],
        [0, 1, 1, 1, 0],
        [1, 1, 1, 1, 0],
        [1, 1, 1, 1, 1],
        [0, 0, 0, 0, 0]
     ]

Input 2:
 A = [

       [1, 1],
       [1, 1]
     ]

Example Output
Output 1:
 9
Output 2:
 4

Example Explanation
Explanation 1:
 The area of the square is 3 * 3 = 9
 
Explanation 2:
 The given matrix is the largest size square possible so area will be 2 * 2 = 4
*/

int Solution::solve(vector<vector<int> > &A)
{
    int n = A.size(), m = A[0].size(), ans = 0;
    for(int i = 0; ans == 0 && i < m; ++i)
        if(A[n-1][i] == 1)
            ans = 1;
    
    for(int i = 0; ans == 0 && i < n; ++i)
        if(A[i][m-1] == 1)
            ans = 1;
    
    for(int i = n-2; i >= 0; --i)
        for(int j = m-2; j >= 0; --j)
            if(A[i][j] == 1)
            {
                A[i][j] = min(A[i+1][j+1], min(A[i+1][j], A[i][j+1]))+1;
                ans = max(ans, A[i][j]);
            }
    
    return ans*ans;
}
