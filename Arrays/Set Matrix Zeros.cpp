// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/set-matrix-zeros/
// decent if done in O(1) space complexity

void Solution::setZeroes(vector<vector<int> > &A)
{
    int n = A.size();
    int m = A[0].size();
    
    bool rowZero = false;
    bool colZero = false;
    
    for(int i = 0; i < n; ++i)
        if(A[i][0] == 0)
            rowZero = true;
            
    for(int i = 0; i < m; ++i)
        if(A[0][i] == 0)
            colZero = true;
            
    
    for(int i = 1; i < n; ++i)
        for(int j = 1; j < m; ++j)
            if(A[i][j] == 0)
            {
                A[i][0] = 0;
                A[0][j] = 0;
            }
    
    for(int i = 1; i < n; ++i)
        for(int j = 1; j < m; ++j)
            if(A[i][0] == 0 || A[0][j] == 0)
                A[i][j] = 0;
    
    if(rowZero)
        for(int i = 0; i < n; ++i)
            A[i][0] = 0;
            
    if(colZero)
        for(int i = 0; i < m; ++i)
            A[0][i] = 0;
}
