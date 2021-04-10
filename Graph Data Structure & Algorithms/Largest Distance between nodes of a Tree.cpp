// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/
// Easy diameter of a tree problem

int maxD = -1;
int firstMax;

void dfs(int src, int parent, vector<int> adj[], int d, bool vis[])
{
    vis[src] = 1;
    if(d > maxD)
    {
        maxD = d;
        firstMax = src;
    }
    for(int i = 0; i < adj[src].size(); ++i)
    {
        int child = adj[src][i];
        if(!vis[child] && child != parent)
        {
            dfs(child, src, adj, d+1, vis);
        }
    }
}

int Solution::solve(vector<int> &A) 
{
    maxD = -1;
    int n = A.size(), root = -1;
    vector<int> adj[n];
    
    for(int i = 0; i < n; ++i)
    {
        if(A[i] == -1)
            root = i;
        
        else
        {
            adj[A[i]].push_back(i);
            adj[i].push_back(A[i]);
        }
    }
    bool vis[n];
    memset(vis, 0, sizeof(vis));
    
    dfs(root, -1, adj, 0, vis);
    
    memset(vis, 0, sizeof(vis));
    
    dfs(firstMax, -1, adj, 0, vis);
    return maxD;
}
