// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/first-missing-integer/
// Good question, new concept
// Ref : https://www.youtube.com/watch?v=-lfHWWMmXXM&t=539s

int Solution::firstMissingPositive(vector<int> &A) 
{
    int n = A.size();
    int ans = -1;
    int i = 0;
    while(i < n)
    {
        while(A[i] != i+1 && A[i] > 0 && A[i] <= n)
        {
            if(A[i] != A[A[i]-1])
                swap(A[i], A[A[i]-1]);
            else
                break;
        }
        ++i;
    }
    
    for(i = 0; i < n; ++i)
        if(A[i] != i+1)
            return i+1;
    
    if(ans == -1)
        return A[n-1] + 1;
}
