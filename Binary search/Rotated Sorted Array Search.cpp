// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/rotated-sorted-array-search/

int Solution::search(const vector<int> &A, int B) 
{
    int i = 0;
    while(A[i] < A[i+1])
    {
        i++;
    }
    int indexLeft = upper_bound(A.begin(), A.begin() + i, B) 
    - lower_bound(A.begin(), A.begin() + i, B);
    
    int rightIndex = upper_bound(A.begin() + i + 1, A.end() , B) 
    - lower_bound(A.begin() + i + 1, A.end(), B);
    
    if(indexLeft)
    {
        return lower_bound(A.begin(), A.begin() + i, B) - A.begin();
    }
    
    if(rightIndex)
    {
        return lower_bound(A.begin() + i + 1, A.end(), B) - A.begin();
    }
    return -1;
}
