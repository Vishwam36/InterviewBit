// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/repeat-and-missing-number-array/
// Good question
// Ref : https://www.youtube.com/watch?v=pnx5JA9LNM4
// Ref : https://www.youtube.com/watch?v=MvklwzVz654

/*
You are given a read only array of n integers from 1 to n.
Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:
Input:[3 1 2 5 3] 
Output:[3, 4] 

A = 3, B = 4
*/

// App 1 : based on Maths

vector<int> Solution::repeatedNumber(const vector<int> &A) 
{
    long long n = A.size();
    long long sum = 0;
    long long sum_sq = 0;
    long long sum_expected = ((n)*(n+1))/2;
    long long sum_sq_expected = ((n)*(n+1)*(2*n+1))/6;
    
    for(int i = 0; i < n; ++i)
    {
        sum += (long long)A[i];
        sum_sq += (long long)A[i]*A[i];
    }
    
    long long a_minus_b = sum - sum_expected;
    long long a_minus_b_into_a_plus_b = sum_sq - sum_sq_expected;
    long long a_plus_b = a_minus_b_into_a_plus_b / a_minus_b;
    
    int a = (a_minus_b + a_plus_b) / 2;
    int b = a_plus_b - a;
    
    return {a,b};
}

// App 2 : Difficult

vector<int> Solution::repeatedNumber(const vector<int> &A) 
{
    int n = A.size();
    
    int a_xor_b = 0;
    for(int val : A)
        a_xor_b ^= val;
    
    for(int i = 1; i <= n; ++i)
        a_xor_b ^= i;
    
    int rsbm = a_xor_b & ~(a_xor_b-1);
    int a = 0, b = 0;
    
    for(int val : A)
        if(((rsbm) & (val)) == 0)
            a ^= val;
        else
            b ^= val;
    
    for(int i = 1; i <= n; ++i)
        if(((rsbm) & (i)) == 0)
            a ^= i;
        else
            b ^= i;
    
    for(int val : A)
        if(a == val)
            return {a, b};
        else if(b == val)
            return {b, a};
}
