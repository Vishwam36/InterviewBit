// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/tiling-with-dominoes/
// Good 

/*
Problem Description
Given an integer A you have to find the number of ways to fill a 3 x A board with 2 x 1 dominoes.
Return the answer modulo 109 + 7 .

NOTE:
See the sample explanation for better understanding.

Problem Constraints
1 <= A <= 105

Input Format
First and only argument is an integer A.

Output Format
Return an integer denoting the number of ways to fill a 3 x A board with 2 x 1 dominoes with modulo 109 + 7.

Example Input
Input 1:
 2

Input 2:
 1

Example Output
Output 1:
 3

Output 2:
 0

Example Explanation
Explanation 1:
 Following are all the 3 possible ways to fill up a 3 x 2 board.
 
Explanation 2:
 Not a even a single way exists to completely fill the grid of size 3 x 1.
*/

// REF : https://www.geeksforgeeks.org/tiling-with-dominoes/

long long MOD = 1000000007;
long long dp[100001][2];

long long rec(int n, int shape)
{
    if(dp[n][shape] != -1)
        return dp[n][shape];
    
    if(n == 0 && shape == 0)
        return !shape;
    if(n <= 1)
        return shape;
    
    if(shape == 0)
        return dp[n][shape] = ((2*rec(n-1, 1)) % MOD + rec(n-2, 0)) % MOD;
    else
        return dp[n][shape] = (rec(n-2, 1) + rec(n-1, 0)) % MOD;
}

int Solution::solve(int n) 
{
    if(n % 2 != 0)
        return 0;
    
    memset(dp, -1, sizeof(dp));
    return rec(n, 0);
}
