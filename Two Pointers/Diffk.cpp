// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/diffk/
// Decent

int Solution::diffPossible(vector<int> &A, int B) 
{
    int i = 0, j = 1, diff = 0;
    
    while(j < A.size())
    {
        diff = A[j] - A[i];
        
        if(diff == B)
            return 1;
        
        if(diff < B)
            ++j;
        
        else if(j-i > 1 && diff > B)
            ++i;
        
        else if(j-i == 1 && diff > B)
        {
            ++i;
            ++j;
        }
    }
    return 0;
}
