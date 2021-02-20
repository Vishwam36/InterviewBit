// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/reverse-bits/
// Basic but important
/*
Reverse the bits of an 32 bit unsigned integer A.
Input:3
Output:3221225472

Explanation
    00000000000000000000000000000011    
=>  11000000000000000000000000000000
*/

unsigned int Solution::reverse(unsigned int A)
{
    int rev = 0;
    for(int i = 0; i < 32; ++i)
    {
        rev = rev << 1;
        rev |= (A & 1);
        A = A >> 1;
    }
    return rev;
}
