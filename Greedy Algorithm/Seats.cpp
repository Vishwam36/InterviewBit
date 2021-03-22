// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/seats/
// Good question
// Ref : https://www.youtube.com/watch?v=SK2ypa7poKg&t=797s

#define MOD 10000003;

int Solution::seats(string A)
{
    long long ans = 0;
    int nop = 0, centreX = 0;
    
    for(int i = 0; i < A.size(); ++i)
        if(A[i] == 'x')
            nop++;
    
    int count = 0;
    for(int i = 0; i < A.size(); ++i)
    {
        if(A[i] == 'x')
        {
            count++;
            
            if(count == nop/2 + 1)
                centreX = i; // position of middle 'x' around which all other x will come
        }
    }
    
    count = 0;
    for(int i = 0; i < A.size(); ++i)
    {
        if(A[i] == 'x')
        {
            // centreX - nop/2 + count is final position count th 'x'
            ans += abs(i - (centreX - nop/2 + count)) % MOD;
            count++;
        }
    }
    
    return ans % MOD;
}
