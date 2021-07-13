// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/atoi/
// Easy

/*
Implement atoi to convert a string to an integer.

Example :
Input : "9 2704"
Output : 9

Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

    Questions:
    Q1. Does string contain whitespace characters before the number?
    A. Yes

    Q2. Can the string have garbage characters after the number?
    A. Yes. Ignore it.

    Q3. If no numeric character is found before encountering garbage characters, what should I do?
    A. Return 0.

    Q4. What if the integer overflows?
    A. Return INT_MAX if the number is positive, INT_MIN otherwise. 
*/

int Solution::atoi(const string s) 
{
    int i = 0;
    long long ans = 0;
    while(i < s.size() && s[i] == ' ')
        ++i;
    
    int sign = 1;
    if(i < s.size() && (s[i] == '-' || s[i] == '+'))
    {
        sign = (s[i] == '+' ? 1 : -1);
        ++i;
    }
    
    while(i < s.size())
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            ans = ans * 10 + (s[i]-'0');
            if(ans > INT_MAX)
                break;
        }
        else
        {
            break;
        }
        ++i;
    }
    
    if(sign == 1)
        return ans > INT_MAX ? INT_MAX : ans;
    return -ans < INT_MIN ? INT_MIN : -ans;
}
