// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/distribute-candy/
// Decent

int Solution::candy(vector<int> &A) 
{
    int n = A.size(), ans = 0;
    
    vector<int> wrtLeft(n, 1);
    vector<int> wrtRight(n, 1);
    
    for(int i = 1; i < n; ++i)
        if(A[i-1] < A[i])
            wrtLeft[i] = wrtLeft[i-1] + 1;
    
    for(int i = n-2; i >= 0; --i)
        if(A[i+1] < A[i])
            wrtRight[i] = wrtRight[i+1] + 1;
    
    for(int i = 0; i < n; ++i)
        ans += max(wrtLeft[i], wrtRight[i]);
    
    return ans;
}
