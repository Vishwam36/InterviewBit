// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/merge-elements/
// Decent

/*
Problem Description
Given an integer array A of size N. You have to merge all the elements of the array into one with the minimum possible cost.

The rule for merging is as follows:
Choose any two adjacent elements of the array with values say X and Y and merge them into a single element with value (X + Y) paying a total cost of (X + Y).
Return the minimum possible cost of merging all elements.

Problem Constraints
1 <= N <= 200
1 <= A[i] <= 103

Input Format
First and only argument is an integer array A of size N.

Output Format
Return an integer denoting the minimum cost of merging all elements.

Example Input
Input 1:
 A = [1, 3, 7]
Input 2:
 A = [1, 2, 3, 4]

Example Output
Output 1:
 15
Output 2:
 19

Example Explanation
Explanation 1:
 All possible ways of merging:
 a) {1, 3, 7} (cost = 0) -> {4, 7} (cost = 4) -> {11} (cost = 4+11 = 15)
 b) {1, 3, 7} (cost = 0) -> {1, 10} (cost = 10) -> {11} (cost = 10+11 = 21)
 Thus, ans = 15
*/

#define ll long long
int n;
ll dp[202][202];

ll rec(int l, int r, vector<int> &A)
{
    if(l >= r)
        return 0;
    
    if(dp[l][r] != -1)
        return dp[l][r];
    
    ll ans = INT_MAX;
    ll sum = 0;
    for(int i = l; i <= r; ++i)
        sum += A[i];
    
    for(int k = l; k < r; ++k)
        ans = min(ans, rec(l, k, A) + rec(k+1, r, A) + sum);
    
    return dp[l][r] = ans;
}

int Solution::solve(vector<int> &A) 
{
    memset(dp, -1, sizeof(dp));
    n = A.size();
    return rec(0, n-1, A);
}
