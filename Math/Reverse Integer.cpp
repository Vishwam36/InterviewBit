// By Vishwam shriram Mundada
// https://www.interviewbit.com/problems/reverse-integer/

int Solution::reverse(int A) 
{
    long ans = 0;
    
    while(A)
    {
        ans = (ans * 10) + (A % 10);
        A /= 10;
    }
        
    if(ans > INT_MAX || ans < INT_MIN)
        return 0;
        
    return ans;
}
