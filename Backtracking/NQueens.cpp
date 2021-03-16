// By Vishwam Shrirsm Mundada
// https://www.interviewbit.com/problems/nqueens/
// Standard good question

vector<vector<string> > ans;

bool isSafe(int x, int y, vector<string> &v, int n)
{
    for(int row = x; row >= 0; --row)
        if(v[row][y] == 'Q')
            return false;
    
    int row = x, col = y;
    while(row >= 0 && col >= 0)
    {
        if(v[row][col] == 'Q')
            return false;
        
        row--;
        col--;
    }
    
    row = x;
    col = y;
    while(row >= 0 && col < n)
    {
        if(v[row][col] == 'Q')
            return false;
        
        row--;
        col++;
    }
    return true;
}

void nQueens(int x, vector<string> &v, int n)
{
    if(x == n)
    {
        ans.push_back(v);
        return;
    }
    
    for(int col = 0; col < n; ++col)
    {
        if(isSafe(x, col, v, n))
        {
            v[x][col] = 'Q';
            nQueens(x+1, v, n);
            v[x][col] = '.'; // backtrack
        }
    }
    return;
}

vector<vector<string> > Solution::solveNQueens(int n)
{
    ans.clear();
    
    // no solution possible for 2x2 and 3x3 boards 
    if(n == 2 || n == 3)
        return ans;
    
    string s(n, '.');
    vector<string> v(n, s);
    
    nQueens(0, v, n);
    return ans;
}
