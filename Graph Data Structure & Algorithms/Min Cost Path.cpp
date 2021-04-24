// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/min-cost-path/
// Decent question

#define pip pair<int, pair<int, int> >
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string dir = "RLDU";


bool isValid(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int Solution::solve(int A, int B, vector<string> &C) 
{
    bool vis[A][B];
    int dis[A][B];
    for(int i = 0; i < A; ++i)
        for(int j = 0; j < B; ++j)
            {
                vis[i][j] = 0;
                dis[i][j] = INT_MAX;
            }
    
    priority_queue<pip, vector<pip>, greater<pip> > pq;
    pq.push({0,{0,0}});
    vis[0][0] = 1;
    dis[0][0] = 0;
    
    while(!pq.empty())
    {
        pip p = pq.top();
        pq.pop();
        
        int x = p.second.first;
        int y = p.second.second;
        int cost = p.first;
        
        vis[x][y] = 1;
        
        if(x == A-1 && y == B-1)
            return cost;
        
        for(int i = 0; i < 4; ++i)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if(!isValid(newX, newY, A, B))
                continue;
            
            if(vis[newX][newY])
                continue;
            
            if(C[x][y] == dir[i])
            {
                dis[newX][newY] = cost;
                pq.push({cost, {newX, newY}});
            }
            else
            {
                if(dis[newX][newY] > dis[x][y] + 1)
                {
                    dis[newX][newY] = dis[x][y] + 1;
                    pq.push({dis[newX][newY], {newX, newY}});
                }
            }
        }
    }
}
