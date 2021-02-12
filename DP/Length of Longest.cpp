// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/length-of-longest-subsequence/
// Simple

int Solution::longestSubsequenceLength(const vector<int> &A) 
{
    int n = A.size();
    
    vector<int> inc(n, 1);
    vector<int> dec(n, 1);
    
    for(int i = 1; i < n; ++i)
        for(int j = 0; j < i; ++j)
            if(A[j] < A[i] && inc[i] < inc[j]+1)
                inc[i] = inc[j] + 1;
    
    for(int i = n-2; i >= 0; --i)
        for(int j = n-1; j > i; --j)
            if(A[i] > A[j] && dec[i] < dec[j]+1)
                dec[i] = dec[j] + 1;
    
    int ans = 0;
    for(int i = 0; i < n; ++i)
        ans = max(ans, inc[i] + dec[i] - 1);
    
    return ans;
}
