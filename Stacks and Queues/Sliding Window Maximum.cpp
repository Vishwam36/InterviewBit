// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/sliding-window-maximum/
// Good question

/*
Given an array of integers A. There is a sliding window of size B which
is moving from the very left of the array to the very right.
You can only see the w numbers in the window. Each time the sliding window moves
rightwards by one position. You have to find the maximum for each window.
The following example will give you more clarity.

The array A is [1 3 -1 -3 5 3 6 7], and B is 3.
Window position 	Max
———————————- 	————————-
[1 3 -1] -3 5 3 6 7 	3
1 [3 -1 -3] 5 3 6 7 	3
1 3 [-1 -3 5] 3 6 7 	5
1 3 -1 [-3 5 3] 6 7 	5
1 3 -1 -3 [5 3 6] 7 	6
1 3 -1 -3 5 [3 6 7] 	7

Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1].

Note: If B > length of the array, return 1 element with the max of the array.

Input Format
The first argument given is the integer array A.
The second argument given is the integer B.

Output Format
Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1]

For Example
Input 1:
    A = [1, 3, -1, -3, 5, 3, 6, 7]
    B = 3
Output 1:
    C = [3, 3, 5, 5, 6, 7]
*/

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) 
{
    deque<int> q;
    vector<int> ans;
    
    int l = 0, r = 0;
    while(r < B)
    {
        while(!q.empty() && q.back() < A[r])
            q.pop_back();
        
        q.push_back(A[r]);
        ++r;
    }
    
    ans.push_back(q.front());
    
    while(r < A.size())
    {
        if(A[l] == q.front())
            q.pop_front();
        ++l;
        
        while(!q.empty() && q.back() < A[r])
            q.pop_back();
        
        q.push_back(A[r]);
        ans.push_back(q.front());
        ++r;
    }
    return ans;
}
