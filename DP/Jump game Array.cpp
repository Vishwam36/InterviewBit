// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/jump-game-array/
// Similar Problem : https://www.interviewbit.com/problems/min-jumps-array/

int Solution::canJump(vector<int> &A) 
{
    int n = A.size();
    
    if(n <= 1)
        return 1;
    
    if(A[0] == 0)
        return 0;
    
    int jumps = 1;
    int steps = A[0];
    int maxReachIndex = A[0];
    
    for(int i = 1; i < n; ++i)
    {
        if(i == n-1)
            return 1;
            
        --steps;
        
        maxReachIndex = max(i + A[i], maxReachIndex);
        
        if(steps == 0)
        {
            steps = maxReachIndex - i;
            jumps++;
        }
        
        if(steps < 0)
            return 0;
    }
    
    return 1;
}
