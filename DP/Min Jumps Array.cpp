// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/min-jumps-array/
// Good problem
// Ref : https://www.youtube.com/watch?v=5Du2iSRrbEw&ab_channel=FriendlyDeveloper

int Solution::jump(vector<int> &A) 
{
    if(A.size() <= 1)
        return 0;
        
    if(A[0] == 0)
        return -1;
    
    int n = A.size();
    int maxReachableIndex = A[0];
    int jumps = 1;
    int steps = A[0];
    
    for(int i = 1; i < n; ++i)
    {
        if(i == n-1)
            return jumps;
            
        maxReachableIndex = max(maxReachableIndex, i+A[i]);
        steps--;
        
        if(steps == 0)
        {
            jumps++;
            steps = maxReachableIndex - i;
        }
        
        if(steps < 0)
            return -1;
    }
    return -1;
}
