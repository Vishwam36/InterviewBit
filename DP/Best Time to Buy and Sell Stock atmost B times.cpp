// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/best-time-to-buy-and-sell-stock-atmost-b-times/
// Easy

/*
Problem Description
Given an array of integers A of size N in which ith element is the price of the stock on day i.
You can complete atmost B transactions.
Find the maximum profit you can achieve.

NOTE: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Problem Constraints
1 <= N <= 500
0 <= A[i] <= 106
0 <= B <= 109

Input Format
The First argument given is the integer array A.
The Second argument is integer B.

Output Format
Return the maximum profit you can achieve by doing atmost B transactions.

Example Input
Input 1:
 A = [2, 4, 1]
 B = 2

Input 2:
 A = [3, 2, 6, 5, 0, 3]
 B = 2

Example Output
Output 1:
 2

Output 2:
 7

Example Explanation
Explanation 1:
 Buy on day 1 (price = 2) and sell on day 2 (price = 4), 
 Profit = 4 - 2 = 2

Explanation 2:
 Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6 - 2 = 4.
 Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3 - 0 = 3.
*/

int dp[501][501];

int rec(int idx, vector<int> &prices, int k, bool bought)
{
    if(idx == prices.size() || k == 0)
        return dp[idx][k] = 0;
    
    if(dp[idx][k] != -1)
        return dp[idx][k];
    
    int ans = 0;
    if(bought)
        ans = rec(idx+1, prices, k-1, 0) + prices[idx];
    else if(!bought)
        ans = rec(idx+1, prices, k-1, 1) - prices[idx];
    
    ans = max(ans, rec(idx+1, prices, k, bought));
    
    return dp[idx][k] = ans;
}

int Solution::solve(vector<int> &prices, int k)
{
    memset(dp, -1, sizeof(dp));
    k = min(2*k, (int)prices.size());
    return rec(0, prices, k, 0);
}
