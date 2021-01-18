// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/rearrange-array/
// (A[A[i]] % n) will give us original value which we had there
// A[i] = A[i]/n is integer division so it will remove original value which we had before and will give correct right value

void Solution::arrange(vector<int> &A) 
{
    int n = A.size();
    for(int i = 0; i < n; ++i)
    {
        A[i] += (A[A[i]] % n) * n;
    }
    for(int i = 0; i < n; ++i)
    {
        A[i] = A[i]/n;
    }
}
 
