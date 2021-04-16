// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/capture-regions-on-board/
// Easy, small trick
/*
Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Problem Constraints
1 <= N, M <= 103

Input Format
First and only argument 2D character matrix A of size N X M.

Output Format
Make changes to the the input only as matrix is passed by reference.

Example Input
Input 1:
 A = [  [X, X, X, X],
        [X, O, O, X],
        [X, X, O, X],
        [X, O, X, X]
     ]

Example Output
Output 1:
 A = [  [X, X, X, X],
        [X, X, X, X],
        [X, X, X, X],
        [X, O, X, X]
     ]


Example Explanation
Explanation 1:
 'O' in (4,2) is not surrounded by X from below.
*/

int n, m;
int hor[] = {-1, 0, 0, 1};
int ver[] = {0, 1, -1, 0};

bool isValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int srcX, int srcY, vector<vector<char> > &A, vector<vector<bool> > &vis)
{
    vis[srcX][srcY] = 1;
    
    queue<pair<int, int> > q;
    q.push({srcX, srcY});
    
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        
        int x = p.first;
        int y = p.second;
        
        for(int i = 0; i < 4; ++i)
        {
            int newX = x + hor[i];
            int newY = y + ver[i];
            
            if(isValid(newX, newY) && !vis[newX][newY] && A[newX][newY] == 'O')
            {
                q.push({newX, newY});
                vis[newX][newY] = 1;
            }
        }
    }
}

void Solution::solve(vector<vector<char> > &A) 
{
    n = A.size(), m = A[0].size();
    vector<vector<bool> > vis(n, vector<bool>(m, 0));
    
    for(int i = 0; i < n; ++i)
    {
        if(!vis[i][0] && A[i][0] == 'O')
            bfs(i, 0, A, vis);
        
        if(!vis[i][m-1] && A[i][m-1] == 'O')
            bfs(i, m-1, A, vis);
    }
    
    for(int i = 0; i < m; ++i)
    {
        if(!vis[0][i] && A[0][i] == 'O')
            bfs(0, i, A, vis);
        
        if(!vis[n-1][i] && A[n-1][i] == 'O')
            bfs(n-1, i, A, vis);
    }
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(!vis[i][j])
                A[i][j] = 'X';
}
