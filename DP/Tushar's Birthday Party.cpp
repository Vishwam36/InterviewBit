// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/tushars-birthday-party/
// Unbounded Knapsack
/*
As it is Tushar’s Birthday on March 1st, he decided to throw a party to all his friends at TGI Fridays in Pune.
Given are the eating capacity of each friend, filling capacity of each dish and cost of each dish. A friend is satisfied if the sum of the filling capacity of dishes he ate is equal to his capacity. Find the minimum cost such that all of Tushar’s friends are satisfied (reached their eating capacity).

NOTE:

Each dish is supposed to be eaten by only one person. Sharing is not allowed.
Each friend can take any dish unlimited number of times.
There always exists a dish with filling capacity 1 so that a solution always exists.

A : Friends : List of integers denoting eating capacity of friends separated by space.
B : Capacity: List of integers denoting filling capacity of each type of dish.
C : Cost :    List of integers denoting cost of each type of dish.
*/

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) 
{
    int n = B.size();
    pair<int,int> dp[1001][n+1];
    
    for(int i = 0; i < 1001; ++i)
        for(int j = 0; j <= n; ++j)
            dp[i][j] = {0, 0};
     
    // dp[i][j].first stores max capacity we can get eith first j dishes
    // dp[i][j].second stores min cost to get capacity = dp[i][j].first
    
    for(int i = 1; i < 1001; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(i >= B[j-1])
            {
                if(B[j-1] + dp[i-B[j-1]][j].first == dp[i][j-1].first)
                {
                    if(dp[i][j-1].second <= dp[i-B[j-1]][j].second + C[j-1])
                    {
                        dp[i][j] = dp[i][j-1];
                    }
                    else
                    {
                        dp[i][j].first = dp[i-B[j-1]][j].first + B[j-1];
                        dp[i][j].second = dp[i-B[j-1]][j].second + C[j-1];
                    }
                }
                else
                {
                    if(dp[i][j-1].first >= dp[i-B[j-1]][j].first + B[j-1])
                    {
                        dp[i][j] = dp[i][j-1];
                    }
                    else
                    {
                        dp[i][j].first = dp[i-B[j-1]][j].first + B[j-1];
                        dp[i][j].second = dp[i-B[j-1]][j].second + C[j-1];
                    }
                }
            }
            else
            {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    int ans = 0;
    
    // dp[i][n].second stores min cost to get capacity i with all n dishes
    for(int i = 0; i < A.size(); ++i)
        ans += dp[A[i]][n].second;
    
    return ans;
}
