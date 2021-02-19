// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
// Simple problem

int Solution::maxSubArray(const vector<int> &A) 
{
    int n = A.size(), tempSum = 0, maxSum = INT_MIN;
    
    for(int i = 0; i < n; ++i)
    {
        if(tempSum + A[i] >= 0)
        {
            tempSum += A[i];
            maxSum = max(maxSum, tempSum);
        }
        else
        {
            maxSum = max(maxSum, A[i]);
            tempSum = 0;
        }
    }
    return maxSum;
}
