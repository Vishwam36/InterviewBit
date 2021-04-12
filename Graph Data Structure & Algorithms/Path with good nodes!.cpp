// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/path-with-good-nodes/
// Easy

int ans = 0;

void dfs(int src, int parent, vector<int> v[], int C, vector<int> &A)
{
    if(C < 0)
        return;
    
    if(v[src].size() == 1)
    {
        ans++;
        return;
    }
    
    for(int i = 0; i < v[src].size(); ++i)
    {
        int child = v[src][i];
        
        if(child != parent && A[child-1] == 1)
            dfs(child, src, v, C-1, A);
        
        else if(child != parent)
            dfs(child, src, v, C, A);
    }
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) 
{
    ans = 0;
    int n = A.size();
    vector<int> v[n+1];
    
    for(int i = 0; i < B.size(); ++i)
    {
        v[B[i][0]].push_back(B[i][1]);
        v[B[i][1]].push_back(B[i][0]);
    }
    
    if(A[0] == 1)
        dfs(1, 0, v, C-1, A);
    else
        dfs(1, 0, v, C, A);
    
    return ans;
}
