// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/
// Solve if you cant detect cycle in directed graph

bool detectCycle(int src, vector<int> v[], int vis[], int rec[])
{
    if(rec[src])
        return true;
    
    if(vis[src])
        return false;
    
    vis[src] = 1;
    rec[src] = 1;
    
    for(int i = 0; i < v[src].size(); ++i)
    {
        int child = v[src][i];
        
        if(!vis[child] && detectCycle(child, v, vis, rec))
            return true;
        
        if(rec[child])
            return true;
    }
    rec[src] = 0;
    return false;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) 
{
    bool ans = false;
    vector<int> v[A+1];
    for(int i = 0; i < B.size(); ++i)
        v[C[i]].push_back(B[i]);
    
    int vis[A+1];
    memset(vis, 0, sizeof(vis));
    int rec[A+1];
    memset(rec, 0, sizeof(rec));
    
    for(int i = 1; i <= A; ++i)
        if(!ans && !vis[i])
            ans = ans || detectCycle(i, v, vis, rec);
    
    return !ans;
}
