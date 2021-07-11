// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/edit-distance/
// Easy

/*
Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:
    Insert a character
    Delete a character
    Replace a character

Input Format:
The first argument of input contains a string, A.
The second argument of input contains a string, B.

Output Format:
Return an integer, representing the minimum number of steps required.

Constraints:
1 <= length(A), length(B) <= 450

Examples:
Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.
*/

int dp[451][451];

int rec(int i, int j, string &A, string &B)
{
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(i == A.size() && j == B.size())
        return dp[i][j] = 0;
    if(i == A.size())
        return dp[i][j] = B.size()-j;
    if(j == B.size())
        return dp[i][j] = A.size()-i;
    
    if(A[i] == B[j])
        return dp[i][j] = rec(i+1, j+1, A, B);
    
    int ans = INT_MAX;
    ans = min(ans, rec(i+1, j, A, B)+1);
    ans = min(ans, rec(i, j+1, A, B)+1);
    ans = min(ans, rec(i+1, j+1, A, B)+1);
    
    return dp[i][j] = ans;
}

int Solution::minDistance(string A, string B) 
{
    memset(dp, -1, sizeof(dp));
    return rec(0, 0, A, B);
}
