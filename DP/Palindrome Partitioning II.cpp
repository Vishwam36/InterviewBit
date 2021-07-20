// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/palindrome-partitioning-ii/
// Decent

/*
Given a string A, partition A such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of A.

Input Format:
The first and the only argument contains the string A.

Output Format:
Return an integer, representing the answer as described in the problem statement.

Constraints:
1 <= length(A) <= 501

Examples:
Input 1:
    A = "aba"

Output 1:
    0

Explanation 1:
    "aba" is already a palindrome, so no cuts are needed.

Input 2:
    A = "aab"
    
Output 2:
    1

Explanation 2:
    Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

int dp[502];

bool isPali(string &s, int l, int r)
{
    while(r > l)
        if(s[l++] != s[r--])
            return false;
    
    return true;
}

int rec(string &s, int l, int r)
{
    if(dp[l] != -1)
        return dp[l];
    
    if(l == r)
        return dp[l] = 0;
    
    if(isPali(s, l, r))
        return dp[l] = 0;
    
    int ans = INT_MAX;
    for(int k = l; k < r; ++k)
    {
        if(isPali(s, l, k))
        {
            ans = min(ans, rec(s, l, k) + rec(s, k+1, r) + 1);
        }
    }
    return dp[l] = ans;
}

int Solution::minCut(string A) 
{
    memset(dp, -1, sizeof(dp));
    return rec(A, 0, A.size()-1);
}
