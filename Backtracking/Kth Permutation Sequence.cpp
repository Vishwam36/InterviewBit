// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/kth-permutation-sequence/
// good question
// Ref : https://www.youtube.com/watch?v=W9SIlE2jhBQ

long long fact(long long n)
{
    if(n > 12) 
        return INT_MAX;
    
    long long f = 1;
    
    for(long long i = 1; i <= n; ++i)
        f *= i;
    
    return f;
}

void rec(vector<int> &digits, long long n, long long k, string &ans)
{
    if(n == 1)
    {
        ans += to_string(digits[0]);
        return;
    }
    
    int index = k / fact(n-1);
    
    if(k % fact(n-1) == 0)
        index -= 1;
    
    k = k - fact(n-1) * index;
    
    ans += to_string(digits[index]);
    
    digits.erase(digits.begin() + index);
    
    rec(digits, n-1, k, ans);
}

string Solution::getPermutation(int n, int k) 
{
    vector<int> digits;
    for(int i = 1; i <= n; ++i)
        digits.push_back(i);
    
    string ans;
    
    rec(digits, n, k, ans);

    return ans;
}
