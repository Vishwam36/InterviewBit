// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/ways-to-color-a-3xn-board/
// Good question

/*
Given a 3 x A board, find the number of ways to color it using at most 4 colors such that no 2 adjacent boxes have same color.
Diagonal neighbors are not treated as adjacent boxes.
Return the ways modulo 109 + 7 as the answer grows quickly.

Input Format:
The first and the only argument contains an integer, A.

Output Format
Return an integer representing the number of ways to color the board.

Constraints:
1 <= A < 100000

Examples:
Input 1:
    A = 1
Output 1:
    36

Input 2:
    A = 2
Output 2:
    588
*/

// REF : https://medium.com/algorithm-and-datastructure/number-of-ways-to-paint-n-3-grid-170b04213d46

#define ll long long 
const long long MOD = 1000000007;

int Solution::solve(int n) 
{
    ll pat1 = 12, pat2 = 24;
    for(int i = 2; i <= n; ++i)
    {
        ll nextPat1 = (pat1*7 + pat2*5) % MOD;
        ll nextPat2 = (pat1*10 + pat2*11) % MOD;
        
        pat1 = nextPat1, pat2 = nextPat2;
    }
    return (pat1 + pat2) % MOD;
}
