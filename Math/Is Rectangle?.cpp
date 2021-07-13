// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/is-rectangle/
// Easy

int Solution::solve(int A, int B, int C, int D)
{
    return (A == B && C == D) || (A == C && B == D) || (A == D && B == C);
}
