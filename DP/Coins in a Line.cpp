// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/coins-in-a-line/
// Decent

/*
Problem Description
There are A coins (Assume A is even) in a line.
Two players take turns to take a coin from one of the ends of the line until there are no more coins left.
The player with the larger amount of money wins, Assume that you go first.
Return the maximum amount of money you can win.

NOTE:
You can assume that opponent is clever and plays optimally.

Problem Constraints
1 <= length(A) <= 500
1 <= A[i] <= 105

Input Format
The first and the only argument of input contains an integer array A.

Output Format
Return an integer representing the maximum amount of money you can win.

Example Input
Input 1:
 A = [1, 2, 3, 4]

Input 2:
 A = [5, 4, 8, 10]

Example Output
Output 1:
 6

Output 2:
 15

Example Explanation
Explanation 1:
 You      : Pick 4
 Opponent : Pick 3
 You      : Pick 2
 Opponent : Pick 1

Total money with you : 4 + 2 = 6

Explanation 2:
 You      : Pick 10
 Opponent : Pick 8
 You      : Pick 5
 Opponent : Pick 4

Total money with you : 10 + 5 = 15
*/

int dp[501][501];

int rec(int l, int r, vector<int> &coin, int sum)
{
    if(l == r)
        return sum;
    
    if(dp[l][r] != -1)
        return dp[l][r];
    
    int ans1 = sum - rec(l+1, r, coin, sum-coin[l]); // picked left
    int ans2 = sum - rec(l, r-1, coin, sum-coin[r]); // picked right
    return dp[l][r] = max(ans1, ans2);
}

int Solution::maxcoin(vector<int> &coin)
{
    int sum = 0;
    for(auto c : coin)
        sum += c;
    
    memset(dp, -1, sizeof(dp));
    return rec(0, coin.size()-1, coin, sum);
}
