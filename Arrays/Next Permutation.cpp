// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/next-permutation/
// Good Question

vector<int> Solution::nextPermutation(vector<int> &A) 
{
    int n = A.size(), idx = -1;
    
    for(int i = n-2; i >= 0; --i)
    {
        if(A[i+1] > A[i])
        {
            idx = i;
            break;
        }
    }
    
    if(idx == -1)
    {
        reverse(A.begin(), A.end());
        return A;
    }
    
    sort(A.begin()+idx+1, A.end());
    for(int i = idx+1; i < n; ++i)
    {
        if(A[i] > A[idx])
        {
            swap(A[i], A[idx]);
            break;
        }
    }
    return A;
}
