// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/step-by-step/
// Easy

/*
Problem Description
Given a target A on an infinite number line, i.e. -infinity to +infinity.
You are currently at position 0 and you need to reach the target by moving according to the below rule:
In ith move you can take i steps forward or backward.

Find the minimum number of moves required to reach the target.

Problem Constraints
-10^9 <= A <= 10^9

Input Format
First and only argument is an integer A.

Output Format
Return an integer denoting the minimum moves to reach target.

Example Input
Input 1:
 3

Input 2:
 2

Example Output
Output 1:
 2

Output 2:
 3

Example Explanation
Explanation 1:
 On the first move we step from 0 to 1.
 On the second step we step from 1 to 3.

Explanation 2:
 On the first move we step from 0 to 1.
 On the second move we step  from 1 to -1.
 On the third move we step from -1 to 2.
*/

/*
If target is negative, we can take it as positive because we start from 0 in symmetrical way.
Idea is to move in one direction as long as possible, this will give minimum moves. Starting at 0 first move takes us to 1, second move takes us to 3 (1+2) 
position, third move takes us to 6 (1+2+3) position, ans so on;
So for finding target we keep on adding moves until we find the nth move such that 1+2+3+…+n>=target.

Keep adding sum = 1 + 2 + .. + n >= target. Solving this quadratic equation gives the smallest n such that sum >= target, 
i.e solving for n in n(n+1) / 2 – target >= 0 gives smallest n.
If sum == target, answer is n. Now next case where sum is greater than target. Find the difference by how much steps index is ahead of target, i.e sum – target.

Case 1 : Difference is even then answer is n, (because there will always a move flipping which will lead to target).
Case 2 : Difference is odd, then take one more step, i.e add n+1 to sum and now again take the difference. If difference is even the n+1 is the answer 
else take one more move and this will certainly make the difference even then answer will be n + 2.

Explanation : Since difference is odd. Target is either odd or even.
case 1 : n is even (1 + 2 + 3 + … + n), then adding n + 1 makes the difference even.
case 2 : n is odd then adding n + 1 doesn’t makes difference even so take one more move, i.e., n+2.
*/

int Solution::solve(int n) 
{
    n = abs(n);
    long long steps = 0;
    long long reach = 0;
    while(reach < n || ((reach-n) % 2))
    {
        steps++;
        reach += steps;
    }
    return steps;
}
