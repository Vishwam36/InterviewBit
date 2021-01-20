// By Vishwam Shriram mundada
// https://www.interviewbit.com/problems/implement-power-function/

int Solution::pow(int x, int n, int d) 
{
    if(x == 0)
    {
        return 0;
    }
    
    long long ans = 1;
    
    if(n == 0)
    {
        ans = 1;
    }
    else if(n == 1)
    {
        ans = x;
    }
    
    else if(n % 2 == 0)
    {
        ans = pow(x, n/2, d);
        ans = (ans) * (ans);
        ans %= d;
    }
    
    else
    {
        ans = pow(x, n/2, d);
        ans = (((ans) * (ans)) % d) * x;
        ans %= d;
    }
    
    if(ans < 0)
    {
        ans = ans % d;
        ans = ans + d;
        return ans;
    }
    return ans % d;
}
