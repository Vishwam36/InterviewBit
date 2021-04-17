// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/two-teams/
// Decent

// vis[i] = 0 represents not visited
// vis[i] = 1 represents color 1
// vis[i] = 2 represents color 2

int dfs(int src, int color, vector<int> adj[], int vis[])
{
    vis[src] = color;
    for(int i = 0; i < adj[src].size(); ++i)
    {
        int child = adj[src][i];
        if(vis[child] == color)
            return 0;
        
        if(vis[child] == 0 && color == 1 && dfs(child, 2, adj, vis) == 0)
            return 0;
        
        if(vis[child] == 0 && color == 2 && dfs(child, 1, adj, vis) == 0)
            return 0;
    }
    return 1;
}

int Solution::solve(int A, vector<vector<int> > &B) 
{
    vector<int> adj[A+1];
    
    int vis[A+1];
    for(int i = 0; i <= A; ++i)
        vis[i] = 0;
    
    for(int i = 0; i < B.size(); ++i)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    
    for(int i = 1; i <= A; ++i)
        if(vis[i] == 0 && dfs(i, 1, adj, vis) == 0)
            return 0;
    
    return 1;
}
