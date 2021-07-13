// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/sub-matrices-with-sum-zero/
// Decent

/*
Given a 2D matrix, find the number non-empty sub matrices, such that the sum of the elements inside the sub matrix is equal to 0. 
(note: elements might be negative).

Example:
Input

-8 5  7
3  7 -8
5 -8  9

Output
2

Explanation
-8 5 7
3 7 -8
5 -8 9

-8 5 7
3 7 -8
5 -8 9
*/

int count(vector<int> v)
{
    int ans = 0;
    unordered_map<int, int> dp;
    dp[0] = 1; // sum 0
    for(int i = 1; i < v.size(); ++i)
        v[i] += v[i-1];
    
    for(int i = 0; i < v.size(); ++i)
    {
        if(dp.find(v[i]) == dp.end())
        {
            dp[v[i]]++;
        }
        else
        {
            ans += dp[v[i]];
            dp[v[i]]++;
        }
    }
    return ans;
}

int Solution::solve(vector<vector<int> > &A) 
{
    if(A.size() == 0 || A[0].size() == 0)
        return 0;
    
    int n = A.size(), m = A[0].size();
    int ans = 0;
    for(int top = 0; top < n; ++top)
    {
        ans += count(A[top]);
        for(int bot = top+1; bot < n; ++bot)
        {
            for(int col = 0; col < m; ++col)
            {
                A[top][col] += A[bot][col];
            }
            ans += count(A[top]);
        }
    }
    return ans;
}
