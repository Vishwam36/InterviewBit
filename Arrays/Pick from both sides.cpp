// By vishwam Shriram Mundada
// https://www.interviewbit.com/problems/pick-from-both-sides/

int Solution::solve(vector<int> &A, int B) 
{
    int n = A.size(), sum = 0;
    long long preSum[n];
    long long postSum[n];
    
    for(int i = 0; i < n; ++i)
    {
        sum += A[i];
        preSum[i] = sum;
    }
    
    sum = 0;
    for(int i = n-1; i>= 0; --i)
    {
        sum += A[i];
        postSum[i] = sum;
    }
    
    long long ans = max(preSum[B-1], postSum[n-B]);
    
    int i = B-2, j = n-1;
    while(i >= 0)
    {
        ans = max(ans, preSum[i] + postSum[j]);
        --i;
        --j;
    }
    
    return ans;
}
