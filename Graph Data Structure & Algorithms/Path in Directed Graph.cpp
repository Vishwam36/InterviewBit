// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/path-in-directed-graph/
// V Easy

bool path(int src, int dest, vector<int> v[], int n)
{
    bool vis[n+1];
    memset(vis, 0, sizeof(vis));
    
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        if(curr == dest)
            return 1;
        
        for(int i = 0; i < v[curr].size(); ++i)
        {
            int child = v[curr][i];
            
            if(!vis[child])
            {
                q.push(child);
                vis[child] = 1;
            }
        }
    }
    return 0;
}

int Solution::solve(int A, vector<vector<int> > &B) 
{
    vector<int> v[A+1];
    for(int i = 0; i < B.size(); ++i)
        v[B[i][0]].push_back(B[i][1]);
    
    return path(1, A, v, A);
}
