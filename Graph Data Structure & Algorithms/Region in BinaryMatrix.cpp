// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/region-in-binarymatrix/
// Easy one

int ver[] = {0, 0, -1, -1, -1, 1, 1, 1};
int hor[] = {-1, 1, -1, 0, 1, -1, 0, 1};
int ans = 0;

bool isValid(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int srcX, int srcY, vector<vector<int> > &A, vector<vector<bool> > &vis)
{
    queue<pair<int, int> > q;
    q.push({srcX, srcY});
    vis[srcX][srcY] = 1;
    int tempAns = 1;
    
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        
        int x = p.first;
        int y = p.second;
        
        for(int i = 0; i < 8; ++i)
        {
            int newX = x + hor[i];
            int newY = y + ver[i];
            
            if(isValid(newX, newY, A.size(), A[0].size()) && !vis[newX][newY] && A[newX][newY] == 1)
            {
                q.push({newX, newY});
                vis[newX][newY] = 1;
                tempAns++;
            }
        }
    }
    ans = max(ans, tempAns);
}

int Solution::solve(vector<vector<int> > &A) 
{
    ans = 0;
    int n = A.size(), m = A[0].size();
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(!vis[i][j] && A[i][j] == 1)
                bfs(i, j, A, vis);
    
    return ans;
}
