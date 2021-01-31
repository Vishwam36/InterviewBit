// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/roman-to-integer/

int value(char c)
{
    switch(c)
    {
        case 'I':
            return 1;
            
        case 'V':
            return 5;
        
        case 'X':
            return 10;
        
        case 'L':
            return 50;
            
        case 'C':
            return 100;
            
        case 'D':
            return 500;
            
        case 'M':
            return 1000;
    }
    return 0;
}

int Solution::romanToInt(string A) 
{
    int ans = 0;
    for(int i = 0; i < A.size(); ++i)
    {
        if(value(A[i]) < value(A[i+1]) && i < A.size()-1)
        {
            ans += value(A[i+1]) - value(A[i]);
            ++i;
        }
        else
        {
            ans += value(A[i]);
        }
    }
    return ans;
}
