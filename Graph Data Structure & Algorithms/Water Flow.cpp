// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/water-flow/
// Easy
/*
Problem Description
Given an N x M matrix A of non-negative integers representing the height of each unit cell in a continent, 
the "Blue lake" touches the left and top edges of the matrix and the "Red lake" touches the right and bottom edges.
Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
Find the number of cells from where water can flow to both the Blue and Red lake.

Problem Constraints
1 <= M, N <= 1000

1 <= A[i][j] <= 109

Input Format
First and only argument is a 2D matrix A.

Output Format
Return an integer denoting the number of cells from where water can flow to both the Blue and Red lake.

Example Input
Input 1:
 A = [
       [1, 2, 2, 3, 5]
       [3, 2, 3, 4, 4]
       [2, 4, 5, 3, 1]
       [6, 7, 1, 4, 5]
       [5, 1, 1, 2, 4]
     ]

Input 2:
 A = [
       [2, 2]
       [2, 2]
     ]

Example Output
Output 1:
 7
Output 2:
 4

Example Explanation
Explanation 1:
 Blue Lake ~   ~   ~   ~   ~ 
        ~  1   2   2   3  (5) *
        ~  3   2   3  (4) (4) *
        ~  2   4  (5)  3   1  *
        ~ (6) (7)  1   4   5  *
        ~ (5)  1   1   2   4  *
           *   *   *   *   * Red Lake
 Water can flow to both lakes from the cells denoted in parentheses.

Explanation 2:
 Water can flow from all cells.
*/

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

int Solution::solve(vector<vector<int> > &A) 
{
    int n = A.size(), m = A[0].size(), ans = 0;
    vector<vector<bool> > visRed(n, vector<bool>(m, 0));
    vector<vector<bool> > visBlue(n, vector<bool>(m, 0));
    
    queue<pair<int, int> > q;
    for(int i = 0; i < n; ++i)
    {
        q.push({i, 0});
        visBlue[i][0] = 1;
    }
    for(int i = 0; i < m; ++i)
    {
        q.push({0, i});
        visBlue[0][i] = 1;
    }
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isValid(nx, ny, n, m) && !visBlue[nx][ny] && A[nx][ny] >= A[x][y])
            {
                q.push({nx, ny});
                visBlue[nx][ny] = 1;
            }
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        q.push({i, m-1});
        visRed[i][m-1] = 1;
    }
    for(int i = 0; i < m; ++i)
    {
        q.push({n-1, i});
        visRed[n-1][i] = 1;
    }
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isValid(nx, ny, n, m) && !visRed[nx][ny] && A[nx][ny] >= A[x][y])
            {
                q.push({nx, ny});
                visRed[nx][ny] = 1;
            }
        }
    }
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(visRed[i][j] && visBlue[i][j])
                ans++;
    
    return ans;
}
