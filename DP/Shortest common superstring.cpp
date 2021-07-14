// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/shortest-common-superstring/
// Good question

/*
Given a set of strings, A of length N.
Return the length of smallest string which has all the strings in the set as substring.

Input Format:
The first and the only argument has an array of strings, A.

Output Format:
Return an integer representing the minimum possible length of the resulting string.

Constraints:
1 <= N <= 18
1 <= A[i] <= 100

Example:
Input 1:
    A = ["aaaa", "aa"]

Output 1:
    4

Explanation 1:
    Shortest string: "aaaa"

Input 2:
    A = ["abcd", "cdef", "fgh", "de"]

Output 2:
    8

Explanation 2:
    Shortest string: "abcdefgh"
*/

// REF : https://www.youtube.com/watch?v=b1HcnDfLzFw&ab_channel=HappyCoding

// cost of merging w1->w2
int mergeCost(string &w1, string &w2)
{
    int matchLen = 0;
    int n1 = w1.size(), n2 = w2.size();
    vector<vector<int> > dp(n1+1, vector<int>(n2+1, 0));
    
    for(int i = 1; i <= n1; ++i)
        for(int j = 1; j <= n2; ++j)
        {
            if(w1[i-1] == w2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            
            matchLen = max(matchLen, dp[i][j]);
        }
    
    if(matchLen == w1.size() || matchLen == w2.size()) // ex. "abcd", "bc" => cost = 0
        return 0;

    matchLen = 0;
    for(int i = 1; i <= min(w1.size(), w2.size()); ++i)
        if(w1.substr(w1.size()-i) == w2.substr(0, i))
            matchLen = i;
    
    return w2.size()-matchLen;
}

int Solution::solve(vector<string> &words)
{
    int n = words.size();
    vector<vector<int> > cost(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(i != j)
                cost[i][j] = mergeCost(words[i], words[j]);
    
    int minCost = INT_MAX, preMask;
    int end = (1 << n) - 1; // 111111  shows that all words are taken
    vector<vector<int> > dp(end+1, vector<int>(n, INT_MAX));
    
    for(int mask = 1; mask <= end; ++mask)
    {
        // check all possible endings for mask
        // dp[mask][j] is min cost to take masked strings with jth string as last taken
        for(int j = 0; j < n; ++j)
        {
            if(((mask) & (1 << j)) == 0)
                continue;
            
            preMask = ((mask) ^ (1 << j));
            
            if(preMask == 0)
            {
                dp[mask][j] = words[j].size();
            }
            else
            {
                // check all possible endings for preMask
                for(int k = 0; k < n; ++k)
                {
                    if(((preMask) & (1 << k)) == 0)
                        continue;
                    
                    if(dp[mask][j] > dp[preMask][k] + cost[k][j])
                    {
                        dp[mask][j] = dp[preMask][k] + cost[k][j];
                    }
                }
            }
            if(mask == end && dp[mask][j] < minCost)
                minCost = dp[mask][j];
        }
    }
    return minCost;
}
