// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/
// Ref : https://www.youtube.com/watch?v=9vYCQLYF6ng&ab_channel=PrakashShukla
// New trick
/*
Given a binary grid A of size N x M consisting of 0's and 1's, 
find the area of the largest rectangle inside the grid such that all the cells inside the chosen rectangle should have 1 in them.
You are allowed to permutate the columns matrix i.e. you can arrange each of the column in any order in the final grid.
*/

int Solution::solve(vector<vector<int> > &A)
{
    int max_area = 1, n = A.size(), m = A[0].size();
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(i != 0 && A[i][j] != 0)
                A[i][j] += A[i-1][j];
    
    for(int i = 0; i < n; ++i)
        sort(A[i].begin(), A[i].end());
    
    for(int i = 0; i < n; ++i)
    {
        int width = 1;
        for(int j = m-1; j >= 0; --j)
        {
            max_area = max(max_area, A[i][j] * width);
            ++width;
        }
    }
    return max_area;
}
