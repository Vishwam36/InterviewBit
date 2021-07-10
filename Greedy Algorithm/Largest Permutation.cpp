// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/largest-permutation/
// Decent

/*
Problem Description

Given an integer array A of size N consisting of unique integers from 1 to N. You can swap any two integers atmost B times.

Return the largest lexicographical value array that can be created by executing atmost B swaps.

Problem Constraints
1 <= N <= 106
1 <= B <= 109

Input Format
First argument is an integer array A of size N.
Second argument is an integer B.

Output Format
Return an integer array denoting the largest lexicographical value array that can be created by executing atmost B swaps.

Example Input
Input 1:
 A = [1, 2, 3, 4]
 B = 1

Input 2:
 A = [3, 2, 1]
 B = 2

Example Output
Output 1:
 [4, 2, 3, 1]

Output 2:
 [3, 2, 1]

Example Explanation
Explanation 1:
 In one swap we can swap (1, 4) so that the array becomes : [4, 2, 3, 1].

Explanation 2:
 Array is already the largest lexicographical value array.
*/

vector<int> Solution::solve(vector<int> &A, int B) 
{
    int n = A.size();
    vector<int> hash(n+1);
    for(int i = 0; i < A.size(); ++i)
        hash[A[i]] = i;
    
    for(int i = 0, j = n; i < A.size() && B; ++i, --j)
    {
        if(A[i] != j) // j should be at ith position
        {
            int id1 = i;
            int id2 = hash[j];
            int ele1 = A[id1];
            int ele2 = A[id2];
            swap(A[id1], A[id2]);
            hash[ele1] = id2;
            hash[ele2] = id1;
            --B;
        }
    }
    return A;
}
