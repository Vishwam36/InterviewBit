// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/pairs-with-given-xor/
// Easy, tricky

/*
Problem Description
Given an 1D integer array A containing N distinct integers.
Find the number of unique pairs of integers in the array whose XOR is equal to B.

NOTE:
    Pair (a, b) and (b, a) is considered to be same and should be counted once.

Problem Constraints
1 <= N <= 105
1 <= A[i], B <= 107

Input Format
First argument is an 1D integer array A.
Second argument is an integer B.

Output Format
Return a single integer denoting the number of unique pairs of integers in the array A whose XOR is equal to B.

Example Input
Input 1:
 A = [5, 4, 10, 15, 7, 6]
 B = 5

Input 2:
 A = [3, 6, 8, 10, 15, 50]
 B = 5
 
Example Output
Output 1:
 1

Output 2:
 2

Example Explanation
Explanation 1:
 (10 ^ 15) = 5

Explanation 2:
 (3 ^ 6) = 5 and (10 ^ 15) = 5 
*/

// Idea :
/**
 *    A ^ B = C
 * => A ^ C = B
 * => B ^ C = A
 */

int Solution::solve(vector<int> &A, int B) 
{
    unordered_set<int> s;
    for(auto num : A)
        s.insert(num^B);
    
    int cnt = 0;
    for(auto num : A)
        if(s.find(num) != s.end())
            cnt++;
    
    return cnt/2;
}
