// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/minimum-difference-subsets/
// Easy, Knapsack variation

/*
Problem Description
Given an integer array A containing N integers.
You need to divide the array A into two subsets S1 and S2 such that the absolute difference between their sums is minimum.
Find and return this minimum possible absolute difference.

NOTE:
Subsets can contain elements from A in any order (not necessary to be contiguous).
Each element of A should belong to any one subset S1 or S2, not both.
It may be possible that one subset remains empty.

Problem Constraints
1 <= N <= 100
1 <= A[i] <= 100

Input Format
First and only argument is an integer array A.

Output Format
Return an integer denoting the minimum possible difference among the sums of two subsets.

Example Input
Input 1:
 A = [1, 6, 11, 5]

Example Output
Output 1:
 1

Example Explanation
Explanation 1:
 Subset1 = {1, 5, 6}, sum of Subset1 = 12
 Subset2 = {11}, sum of Subset2 = 11
*/

int Solution::solve(vector<int> &A) 
{
    int dp[201][2001];
    memset(dp, 0, sizeof(dp));
    int totalSum = 0;
    for(auto num : A)
        totalSum += num;
    
    int sum1 = INT_MIN;
    int reqSum = totalSum/2;
    
    int n = A.size();
    for(int i = 1; i <= reqSum; ++i)
        dp[0][i] = 0;
    for(int i = 0; i <= n; ++i)
        dp[i][0] = 1;
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= reqSum; ++j)
            if(A[i-1] >= 0)
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
    
    for(int i = reqSum; i >= 0; --i)
        if(dp[n][i] == 1)
        {
            sum1 = i;
            break;
        }
    
    return totalSum - 2*sum1;
}
