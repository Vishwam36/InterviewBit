// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/rotate-matrix/
// Decent

void Solution::rotate(vector<vector<int> > &A)
{
    int n = A.size();
    
    int temp = 0, l = 0, r = n-1, t = 0, b = n-1;
    
    while(l < r && t < b)
    {
        for(int i = l; i < r; ++i)
        {
            temp = A[t][i];
            swap(temp, A[i][r]);
            swap(temp, A[b][n-i-1]);
            swap(temp, A[n-i-1][l]);
            swap(temp, A[t][i]);
        }
        ++l; --r;
        ++t; --b;
    }
}
