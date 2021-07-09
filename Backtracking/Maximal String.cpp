// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/maximal-string/
// Easy

/*
Problem Description
Given a string A and integer B, what is maximal lexicographical stringthat can be made from A if you do atmost B swaps.

Problem Constraints
1 <= |A| <= 9

A contains only digits from 0 to 9.

1 <= B <= 5

Input Format
First argument is string A.

Second argument is integer B.

Output Format
Return a string, the naswer to the problem.

Example Input
Input 1:
A = "254"
B = 1

Input 2:
A = "254'
B = 2

Example Output
Output 1:
 524
Output 2:
 542
 
Example Explanation
Explanation 1:
 Swap 2 and 5.
 
Explanation 2:
Swap 2 and 5 then swap 4 and 2.
*/

string maxString;

void swapRec(string &A, int b)
{
    if(b == 0)
        return;
    
    for(int i = 0; i < A.size(); ++i)
    {
        for(int j = i+1; j < A.size(); ++j)
        {
            swap(A[i], A[j]);
            maxString = max(maxString, A);
            swapRec(A, b-1);
            swap(A[i], A[j]);
        }
    }
}

string Solution::solve(string A, int B)
{
    maxString = A;
    swapRec(A, B);
    return maxString;
}
