// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/find-duplicate-in-array/
// Beautiful problem, similar to find start node of loop in linked list
// Ref : https://www.youtube.com/watch?v=32Ll35mhWg0
/*
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in 
linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input: [3 4 1 4 1]
Sample Output: 1
*/

int Solution::repeatedNumber(const vector<int> &A) 
{
    int slow = A[0], fast = A[A[0]];
    
    while(slow != fast)
    {
        slow = A[slow];
        fast = A[A[fast]];
    }
    
    slow = 0;
    while(slow != fast)
    {
        slow = A[slow];
        fast = A[fast];
    }
    
    // there is no point in returning -1 because we'll surely have atleast one duplicate
    // beacuse we have array of n + 1 integers between 1 and n
    return slow;
}
