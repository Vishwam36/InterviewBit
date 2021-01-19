// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/palindrome-integer/

// Solution by Interviewbit ... simple but nice trick used

int reverse(int A) 
{
    int rev=0;
    while(A > 0) 
    {
        rev = rev * 10 + A % 10;
        A = A / 10;
    }
    return rev;
}

int Solution::isPalindrome(int A) 
{
   return A == reverse(A);
}

// My solution 

int Solution::isPalindrome(int A) 
{
    string s = to_string(A);
    string rs = s;
    reverse(rs.begin(), rs.end());
    return s == rs;
}
