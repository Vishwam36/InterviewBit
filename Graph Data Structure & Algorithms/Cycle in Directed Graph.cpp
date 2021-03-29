// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/cycle-in-directed-graph/
// Must learn basic algorithm

bool dfs(vector<int> adj[], int node, int visited[], int rec[])
{
    if(rec[node] == 1)
        return true;
    
    if(visited[node] == 1)
        return false;
    
    visited[node] = 1;
    rec[node] = 1;
    
    for(int i = 0; i < adj[node].size(); ++i)
    {
        int next = adj[node][i];
        
        if(!visited[next] && dfs(adj, next, visited, rec))
            return true;
        if(rec[next] == 1)
            return true;
    }
    rec[node] = 0;
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) 
{
    vector<int> adj[A+1];
    
    for(int i = 0; i < B.size(); ++i)
        adj[B[i][0]].push_back(B[i][1]);
    
    int visited[A+1] = {0};
    int rec[A+1] = {0};
    
    for(int i = 1; i <= A; ++i)
        if(!visited[i])
            if(dfs(adj, i, visited, rec))
                return 1;
    
    return 0;
}
