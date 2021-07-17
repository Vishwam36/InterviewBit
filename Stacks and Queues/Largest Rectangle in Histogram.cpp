// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/largest-rectangle-in-histogram/
// IMP

/*
Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of
the ith histogram’s bar. Width of each bar is 1.

Largest Rectangle in Histogram: Example 1
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

Largest Rectangle in Histogram: Example 2
The largest rectangle is shown in the shaded area, which has area = 10 unit.

Find the area of largest rectangle in the histogram.

Input Format
The only argument given is the integer array A.

Output Format
Return the area of largest rectangle in the histogram.

For Example
Input 1:
    A = [2, 1, 5, 6, 2, 3]
Output 1:
    10
    Explanation 1:
        The largest rectangle is shown in the shaded area, which has area = 10 unit.
*/

int Solution::largestRectangleArea(vector<int> &A) 
{
    int n = A.size();
    vector<int> leftSmaller(n, -1), rightSmaller(n, n);
    
    stack<int> s;
    s.push(n-1);
    for(int i = n-2; i >= 0; --i)
    {
        while(!s.empty() && A[s.top()] >= A[i])
            s.pop();
        
        if(!s.empty())
            rightSmaller[i] = s.top();
        
        s.push(i);
    }
    
    while(!s.empty())
        s.pop();
    
    s.push(0);
    for(int i = 1; i < n; ++i)
    {
        while(!s.empty() && A[s.top()] >= A[i])
            s.pop();
        
        if(!s.empty())
            leftSmaller[i] = s.top();
        
        s.push(i);
    }
    
    int ans = 0;
    for(int i = 0; i < n; ++i)
        ans = max(ans, A[i]*(rightSmaller[i] - leftSmaller[i]-1));
    
    return ans;
}
