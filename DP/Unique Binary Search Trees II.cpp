// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/unique-binary-search-trees-ii/
// Easy

/*
Given an integer A, how many structurally unique BST’s (binary search trees) exist that can store values 1…A?

Input Format:
The first and the only argument of input contains the integer, A.

Output Format:
Return an integer, representing the answer asked in problem statement.

Constraints:
1 <= A <= 18

Example:
Input 1:
    A = 3

Output 1:
    5

Explanation 1:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

int dp[20];

int rec(int n)
{
    if(n <= 1)
        return 1;
    
    if(!dp[n])
        return dp[n];
    
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        ans += rec(i-1) * rec(n-i);
    
    return dp[n] = ans;
}

int Solution::numTrees(int A)
{
    memset(dp, -1, sizeof(dp));
    return rec(A);
}
