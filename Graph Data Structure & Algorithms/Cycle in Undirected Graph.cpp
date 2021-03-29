// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/cycle-in-undirected-graph/
// Must learn basic algo

bool dfs(int node, vector<int> adj[], int visited[], int parent)
{
    visited[node] = 1;
    
    for(int i = 0; i < adj[node].size(); ++i)
    {
        int next = adj[node][i];
        
        if(visited[next] && next != parent)
            return true;
        
        if(!visited[next] && dfs(next, adj, visited, node))
            return true;
    }
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) 
{
    vector<int> adj[A+1];
    
    for(int i = 0; i < B.size(); ++i)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    
    int visited[A+1] = {0};

    for(int i = 1; i <= A; ++i)
        if(!visited[i] && dfs(i, adj, visited, -1))
            return 1;
    
    return 0;
}
