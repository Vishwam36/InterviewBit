// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/remove-consecutive-characters/
// Easy

/*
Problem Description
Given a string A and integer B, remove all consecutive same characters that have length exactly B.

Problem Constraints
1 <= |A| <= 100000
1 <= B <= |A|

Input Format
First Argument is string A.
Second argument is integer B.

Output Format
Return a string after doing the removals.

Example Input
Input 1:
A = "aabcd"
B = 2

Input 2:
A = "aabbccd"
B = 2

Example Output
Output 1:
 "bcd"

Output 2:
 "d"

Example Explanation
Explanation 1:
 "aa" had length 2.

Explanation 2:
 "aa", "bb" and "cc" had length of 2.
*/

string Solution::solve(string A, int B)
{
    string ans;
    for(int i = 0; i < A.size();)
    {
        string temp;
        int j = i;
        while(j < A.size() && A[j] == A[i])
            temp.push_back(A[j++]);
        
        if(temp.size() != B)
            ans += temp;
        i = j;
    }
    return ans;
}
