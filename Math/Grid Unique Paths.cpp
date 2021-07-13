// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/grid-unique-paths/
// Easy

/*
A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).

Path Sum: Example 1
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the 
diagram below).
How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :
Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)
*/


// Basically question is no. of ways to arrange (A--) 1s and (B--) 0s
// which is (A+B)! / (A! * B!)

long long ncr(int n, int r)
{
    int r2 = n-r;
    long long ans = 1;
    while(n > r)
    {
        ans *= n--;

        while(r2 && ans % r2 == 0)
            ans /= r2--;
    }
    return ans;
}

int Solution::uniquePaths(int A, int B) 
{
    A--;
    B--;
    return ncr(A+B, A);
}
