// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/remove-element-from-array/
// Simple

int Solution::removeElement(vector<int> &A, int B)
{
    int n = A.size(), i = 0, j = 0;
    
    for(i = 0; i < n; ++i)
    {
        if(A[i] != B)
        {
            A[j] = A[i];
            ++j;
        }
    }
    return j;
}
