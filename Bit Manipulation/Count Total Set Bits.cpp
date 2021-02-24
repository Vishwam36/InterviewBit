// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/count-total-set-bits/
// Good question
// Ref : https://www.youtube.com/watch?v=kU5G5-6xEF4&t=442s&ab_channel=bhaicodekaro

#define mod 1000000007;
typedef long long ll;

ll leftMostSet(ll n)
{
    ll nob = ceil(log2(n))+1, ans = 0;
    for(ll i = 0; i < nob; ++i)
        if(((n) & (1 << i)) != 0)
            ans = i;
    
    return ans;
}

ll countSetBits(ll n)
{
    if(n == 0)
        return 0;
    
    ll p = leftMostSet(n);
    
    if(n == ((1 << p+1) - 1))
        return ((p+1) * (1 << p));
    
    n = n - (1 << p);
    
    return (p * (1 << p))/2 + (n + 1) + countSetBits(n);
}


int Solution::solve(int A) 
{
    return countSetBits(A) % mod
}
