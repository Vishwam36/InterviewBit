// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/snake-ladder-problem/
// Decent 

int bfs(vector<vector<int> > &v)
{
    int steps = 0;
    
    vector<vector<bool> > vis(100, vector<bool>(100, 0));
    queue<int> q;
    q.push(1);
    vis[0][0] = 1;
    
    while(!q.empty())
    {
        int size = q.size();
        
        while(size--)
        {
            int curr = q.front();
            q.pop();
        
            if(curr == 100)
                return steps;
            
            for(int i = 1; i <= 6; ++i)
            {
                if(curr + i > 100)
                    break;
                
                int x = (curr+i-1)/10;
                int y = (curr+i-1)%10;
                
                if(!vis[x][y])
                {
                    vis[x][y] = 1;
                    q.push(v[x][y]);
                }
            }
        }
        steps++;
    }
    return -1;
}

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) 
{
    int n = A.size(), m = B.size();
    vector<vector<int> > v(100, vector<int>(100, 0));
    
    for(int i = 0; i < 100; ++i)
        for(int j = 0; j < 100; ++j)
            v[i][j] = i*10 + j+1;
    
    for(int i = 0; i < n; ++i)
    {
        int x = (A[i][0]-1)/10;
        int y = (A[i][0]-1) % 10;
        
        v[x][y] = A[i][1];
    }
    for(int i = 0; i < m; ++i)
    {
        int x = (B[i][0]-1)/10;
        int y = (B[i][0]-1) % 10;
        
        v[x][y] = B[i][1];
    }
    return bfs(v);
}
