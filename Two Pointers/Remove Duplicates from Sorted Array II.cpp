// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/
// easy

int Solution::removeDuplicates(vector<int> &A) 
{
    int n = A.size();
    if(n <= 2)
        return n;
    
    int i = 2, j = 0, cnt = 0;
    for(j = 2; j < n; ++j)
    {
        if(A[j] != A[i-2] || A[j] != A[i-1])
        {
            A[i] = A[j];
            ++i;
        }
    }
    A.erase(A.begin()+i, A.end());
    return A.size();
}
