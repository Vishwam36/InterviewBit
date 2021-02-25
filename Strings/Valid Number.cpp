// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/valid-number/
// Too much conditions
/*
Ignore the leading and trailing white spaces.
Ignore the ‘+’, ‘-‘ and’.’ at the start.
Ensure that the characters in the string belong to {+, -, ., e, [0-9]}
Ensure that no ‘.’ comes after ‘e’.
A dot character ‘.’ should be followed by a digit.
The character ‘e’ should be followed either by ‘+’, ‘-‘, or a digit.
*/

bool valid(char c)
{
    if((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '.' || c == 'e')
        return true;
        
    return false;
}

bool digit(char c)
{
    if(c >= '0' && c <= '9')
        return true;
        
    return false;
}

int Solution::isNumber(const string A) 
{
    int n = A.size(), j = 0, k = n-1;
    
    while(A[j] == ' ' && j < n)
        ++j;
    while(A[k] == ' ')
        --k;
    
    if(j > k)
        return 0;
    
    bool ePresent = false;
    for(int i = j; i <= k; ++i)
    {
        if(!valid(A[i]))
            return 0;
            
        if(A[i] == 'e')
        {
            ePresent = true;
            if(i == k)
                return 0;
                
            if(!digit(A[i+1]) && (A[i+1] != '+' && A[i+1] != '-'))
                return 0;
        }
        else
        {
            if(ePresent == true && A[i] == '.')
                return 0;
        }
        if(A[i] == '.')
        {
            if(i == k)
                return 0;
                
            if(!digit(A[i+1]))
                return 0;
        }
        if(A[i] == '+' || A[i] == '-')
        {
            if(i == k)
                return 0;
        }
    }
    return 1;
}
