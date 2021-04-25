// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/permutation-swaps/
// Good question

int find_parent(int a, int parent[])
{
    if(parent[a] == a)
        return a;
    
    int p = find_parent(parent[a], parent);
    parent[a] = p;
    return p;
}

void union_set(int a, int b, int parent[])
{
    int pa = find_parent(a, parent);
    int pb = find_parent(b, parent);
    
    if(pa == pb)
        return;
    
    parent[pb] = pa;
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) 
{
    int parent[A.size()+1];
    for(int i = 0; i <= A.size(); ++i)
        parent[i] = i;
    
    for(int i = 0; i < C.size(); ++i)
        union_set(A[C[i][0]-1], A[C[i][1]-1], parent);
    
    for(int i = 0; i < A.size(); ++i)
    {
        if(A[i] != B[i])
        {
            int p1 = find_parent(A[i], parent);
            int p2 = find_parent(B[i], parent);
            
            if(p1 != p2)
                return 0;
        }
    }
    return 1;
}
