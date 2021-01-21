// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/square-root-of-integer/
// easy one

int Solution::sqrt(int A) 
{
    if(A == 1)
    {
        return 1;
    }
    long long l = 0, r = A, mid = 0;
    while(r - l > 1)
    {
        mid = (l + r) / 2;
        if(mid * mid == A)
        {
            return mid;
        }
        
        else if(mid * mid > A)
        {
            r = mid - 1;
        }
        
        else
        {
            l = mid;
        }
    }
    if(r * r <= A)
    {
        return r;
    }
    return l;
}
