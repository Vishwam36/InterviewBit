// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/
// Simple

int Solution::removeDuplicates(vector<int> &A) 
{
    if(A.size() <= 1)
        return A.size();
    
    int i = 0;
    for(int j = 0; j < A.size()-1; ++j)
    {
        while(A[j] == A[j+1])
            ++j;
        
        A[i] = A[j];
        ++i;
    }
    
    if(A[i-1] != A.back())
    {
        A[i] = A.back();
        ++i;
    }
    
    A.erase(A.begin() + i, A.end());
    return A.size();
}
