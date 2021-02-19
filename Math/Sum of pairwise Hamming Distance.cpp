// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/
// Easy
/*
Hamming distance between two non-negative integers is defined as 
the number of positions at which the corresponding bits are different.

A = [2, 4, 6]
We return, f(2, 2) + f(2, 4) + f(2, 6) + f(4, 2) + f(4, 4) + f(4, 6) + f(6, 2) + f(6, 4) + f(6, 6) = 8
*/

int Solution::hammingDistance(const vector<int> &A) 
{
    long long n = A.size(), count = 0;
    long long ans = 0, mod = 1000000007;
    for(int i = 0; i < 32; ++i)
    {
        count = 0;
        
        for(int j = 0; j < n; ++j)
            if(((A[j]) & (1 << i)) != 0)
                count++;
        
        ans += count * (n - count) * 2;
        ans %= mod;
    }
    return ans;
}
