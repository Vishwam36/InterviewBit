// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/rain-water-trapped/
// Decent

/*
Problem Description
Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Problem Constraints
1 <= |A| <= 100000

Input Format
The only argument given is integer array A.

Output Format
Return the total water it is able to trap after raining.

Example Input
Input 1:
 A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
 
Input 2:
 A = [1, 2]

Example Output
Output 1:
 6
Output 2:
 0

Example Explanation
Explanation 1:
 In this case, 6 units of rain water (blue section) are being trapped.
Explanation 2:
 No water is trapped.
*/

int Solution::trap(const vector<int> &A) 
{
    int n = A.size();
    vector<int> nextGreater(n, -1), preGreater(n, -1);
    
    int leftMax = A[0];
    preGreater[0] = A[0];
    for(int i = 1; i < n; ++i)
    {
        leftMax = max(leftMax, A[i]);
        preGreater[i] = leftMax;
    }
    
    int rightMax = A[n-1];
    nextGreater[n-1] = A[n-1];
    for(int i = n-2; i >= 0; --i)
    {
        rightMax = max(rightMax, A[i]);
        nextGreater[i] = rightMax;
    }
    
    int totalSum = 0;
    for(int i = 0; i < n; ++i)
        totalSum += min(preGreater[i], nextGreater[i]) - A[i];
    
    return totalSum;
}
