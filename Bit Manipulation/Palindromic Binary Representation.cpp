// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/palindromic-binary-representation/
// Very Good question
// Ref : https://www.youtube.com/watch?v=yE_9Bp6bbiw

int rev(int n)
{
    int ans = 0;
    while(n)
    {
        ans = ans << 1;
        ans |= (n & 1);
        n = n >> 1;
    }
    return ans;
}

int Solution::solve(int A)
{
    if(A == 1)
        return 1;
    
    int len = 1, count = 1, temp = 0, ans = 0;
    
    while(count < A)
    {
        len++;
        if(len % 2 == 0)
            temp = (len - 2) / 2;
        else
            temp = len / 2;
        
        count += pow(2, temp);
    }
    
    count -= pow(2, temp);
    ans = pow(2, len-1);
    A = A - count - 1;
    ans |= (A << ((len)/2));
    ans |= rev(ans);
    return ans;
}
