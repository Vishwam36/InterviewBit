// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/sort-by-color/
// Simple

void Solution::sortColors(vector<int> &A)
{
    int zero = 0, two = A.size()-1, i = 0;
    while(i <= two)
    {
        if(A[i] == 0)
            swap(A[i++], A[zero++]);
            
        else if(A[i] == 2)
            swap(A[i], A[two--]);
            
        else
            i++;
    }
}
