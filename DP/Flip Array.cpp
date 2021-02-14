// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/flip-array/
// Variety of knapsack
/*
Given an array of positive elements, you have to flip the sign of some of its elements such that 
the resultant sum of the elements of array should be minimum non-negative(as close to zero as possible). 
Return the minimum no. of elements whose sign needs to be flipped such that the resultant sum is minimum non-negative.
*/
/* 
Approach
Let the sum of all the given elements be S.
This problem can be reduced to a Knapsack problem where we have to fill a Knapsack of capacity (S/2) as fully as possible
and using the minimum no. of elements. We will fill the Knapsack with the given elements. 
Sign of all the elements which come into the knapsack will be flipped.

As sum of all the elements in the Knapsack will be as close to S/2 as possible, 
we are indirectly calculating minimum non-negative sum of all the elements after flipping the sign.
*/

int Solution::solve(const vector<int> &A) 
{
    int n = A.size();
    int sum = 0;
    
    for(int i = 0; i < n; ++i)
        sum += A[i];
        
    sum = sum/2;
    
    pair<int, int> dp[n+1][sum+1];
    // dp[i][j].first will store maximum sum <= j which is possible with first i elements
    // dp[i][j].second will store minimum number of elements required to get sum = dp[i][j].first
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j <= sum; ++j)
            dp[i][j] = {0,0};
    
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= sum; ++j)
        {
            if(j >= A[i-1])
            {
                if(dp[i-1][j - A[i-1]].first + A[i-1] == dp[i-1][j].first)
                {
                    if(dp[i-1][j - A[i-1]].second + 1 < dp[i-1][j].second)
                    {
                        dp[i][j].first = dp[i-1][j - A[i-1]].first + A[i-1];
                        dp[i][j].second = dp[i-1][j - A[i-1]].second + 1;
                    }
                    else
                    {
                        dp[i][j].first = dp[i-1][j].first;
                        dp[i][j].second = dp[i-1][j].second;
                    }
                }
                else
                {
                    if(dp[i-1][j - A[i-1]].first + A[i-1] > dp[i-1][j].first)
                    {
                        dp[i][j].first = dp[i-1][j - A[i-1]].first + A[i-1];
                        dp[i][j].second = dp[i-1][j - A[i-1]].second + 1;
                    }
                    else
                    {
                        dp[i][j].first = dp[i-1][j].first;
                        dp[i][j].second = dp[i-1][j].second;
                    }
                }
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum].second;
}
