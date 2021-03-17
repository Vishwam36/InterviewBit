// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/sudoku/
// Standard good question

bool isSafe(int x, int y, vector<vector<char> > &A, char c)
{
    for(int i = 0; i < 9; ++i)
        if(A[x][i] == c)
            return false;
    
    for(int i = 0; i < 9; ++i)
        if(A[i][y] == c)
            return false;
    
    int startRow = (x/3)*3, startCol = (y/3)*3;
    
    for(int i = startRow; i < startRow+3; ++i)
        for(int j = startCol; j < startCol+3; ++j)
            if(A[i][j] == c)
                return false;
    
    return true;
}

bool rec(int row, int col, vector<vector<char> > &A)
{
    if(row == 9)
        return true;
    
    if(col == 9)
        return rec(row+1, 0, A);
    
    if(A[row][col] != '.')
        return rec(row, col+1, A);
    
    for(char c = '1'; c <= '9'; ++c)
    {
        if(isSafe(row, col, A, c))
        {
            A[row][col] = c;
            
            if(rec(row, col, A))
                return true;
            
            A[row][col] = '.';
        }
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A)
{
    rec(0, 0, A);
}
