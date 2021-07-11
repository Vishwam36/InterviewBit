// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/repeating-subsequence/
// Easy

/*
Problem Description
Given a string A, find length of the longest repeating sub-sequence such that the two subsequence don’t have same string character at same position,
i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

NOTE: Sub-sequence length should be greater than or equal to 2.

Problem Constraints
1 <= |A| <= 100

Input Format
The first and the only argument of input contains a string A.

Output Format
Return an integer, 0 or 1:
    => 0 : False
    => 1 : True

Example Input
Input 1:
 A = "abab"

Input 2:
 A = "abba"

Example Output
Output 1:
 1

Output 2:
 0

Example Explanation
Explanation 1:
 "ab" is repeated.

Explanation 2:
 There is no repeating subsequence.
*/

// question becomes longest common subsequence between A and A, with subsequences having different indices

int dp[101][101];

int rec(int i, int j, string &s, string &t)
{
    if(i == s.size() || j == s.size())
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(s[i] == s[j] && i != j)
        return dp[i][j] = rec(i+1, j+1, s, t)+1;
    
    int ans = 0;
    ans = max(ans, rec(i+1, j, s, t));
    ans = max(ans, rec(i, j+1, s, t));
    
    return dp[i][j] = ans;
}

int Solution::anytwo(string A) 
{
    memset(dp, -1, sizeof(dp));
    string copy = A;
    return rec(0, 0, A, copy) >= 2;
}
