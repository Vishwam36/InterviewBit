// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/valid-sudoku/
// Easy

/*
Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx
The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.

The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]

A partially filled sudoku which is valid.

    Note:
        A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

int Solution::isValidSudoku(const vector<string> &mat) 
{
    unordered_set<char> s;
    
    // check for rows
    for(int i = 0; i < 9; ++i)
    {
        s.clear();
        for(int j = 0; j < 9; ++j)
        {
            if(mat[i][j] != '.' && s.find(mat[i][j]) == s.end())
                s.insert(mat[i][j]);
            else if(s.find(mat[i][j]) != s.end())
                return 0;
        }
    }
    
    // check for columns
    for(int j = 0; j < 9; ++j)
    {
        s.clear();
        for(int i = 0; i < 9; ++i)
        {
            if(mat[i][j] != '.' && s.find(mat[i][j]) == s.end())
                s.insert(mat[i][j]);
            else if(s.find(mat[i][j]) != s.end())
                return 0;
        }
    }
    
    // check for 3x3 blocks
    for(int i = 0; i < 9; i+=3)
    {
        for(int j = 0; j < 9; j+=3)
        {
            // now (i,j) points to the top-left corner of block
            s.clear();
            for(int ii = i; ii < i+3; ++ii)
            {
                for(int ij = j; ij < j+3; ++ij)
                {
                    if(mat[ii][ij] != '.' && s.find(mat[ii][ij]) == s.end())
                        s.insert(mat[ii][ij]);
                    else if(s.find(mat[ii][ij]) != s.end())
                        return 0;
                }
            }
        }
    }
    return 1;
}
