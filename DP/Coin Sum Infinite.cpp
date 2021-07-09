// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/coin-sum-infinite/
// Decent for O(N) space

/*
You are given a set of coins S. In how many ways can you make sum N assuming you have infinite amount of each coin in the set.

Note : Coins in set S will be unique. Expected space complexity of this problem is O(N).

Example :
Input : 
	S = [1, 2, 3] 
	N = 4

Return : 4
Explanation : The 4 possible ways are
{1, 1, 1, 1}
{1, 1, 2}
{2, 2}
{1, 3}	

Note that the answer can overflow. So, give us the answer % 1000007
*/

int Solution::coinchange2(vector<int> &A, int B) 
{
    int dp[B+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    for(auto coin : A)
        for(int i = 1; i <= B; ++i)
            if(i-coin >= 0)
            {
                dp[i] += dp[i-coin];
                dp[i] %= 1000007;
            }
    
    return dp[B];
}
