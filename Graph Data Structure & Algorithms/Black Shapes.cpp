// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/black-shapes/
// Easy

int ver[] = {0, 0, 1, -1};
int hor[] = {-1, 1, 0, 0};
int ans = 0;

bool isValid(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int srcX, int srcY, vector<string> &A, vector<vector<bool> > &vis)
{
    queue<pair<int, int> > q;
    q.push({srcX, srcY});
    vis[srcX][srcY] = 1;
    
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            int x = p.first + hor[i];
            int y = p.second + ver[i];
            
            if(isValid(x, y, A.size(), A[0].size()) && !vis[x][y] && A[x][y] == 'X')
            {
                q.push({x, y});
                vis[x][y] = 1;
            }
        }
    }
}

int Solution::black(vector<string> &A) 
{
    ans = 0;
    int n = A.size(), m = A[0].size();
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(!vis[i][j] && A[i][j] == 'X')
            {
                bfs(i, j, A, vis);
                ++ans;
            }
    
    return ans;
}
