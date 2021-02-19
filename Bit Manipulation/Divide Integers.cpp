// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/divide-integers/
// Good Question
// Ref : https://www.youtube.com/watch?v=X2Ko1Jt9bL4&ab_channel=bhaicodekaro
/*
Idea is to write A in terms of powers of 2 and B
A = B*pow(2,x1) + B*pow(2,x2)+....+ (some values < B which we dont care) x1 > x2 and ...
A/B = pow(2,x1) + pow(2,x2) + ... + 0
*/

int Solution::divide(int x, int y) 
{
    long long A = x, B = y, ans = 0;
    
    int sign = 0;
    if((A < 0 && B > 0) || (A > 0 && B < 0))
        sign = 1;
    
    if(A < 0)
        A *= -1;
    
    if(B < 0)
        B *= -1;
    
    for(int i = 31; i >= 0; --i)
    {
        if((B << i) <= A)
        {
            ans += (1ll << i);
            A -= (B << i);
        }
    }
    
    if(sign == 1)
        ans *= -1;
    
    if(ans > INT_MAX || ans < INT_MIN)
        return INT_MAX;
    
    return ans;
}
