// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/commutable-islands/
// Easy union set

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int find_parent(int a, int p[])
{
    if(p[a] == a)
        return a;
    
    int parent = find_parent(p[a], p);
    p[a] = parent;
    return parent;
}

bool union_set(int a, int b, int p[])
{
    int pa = find_parent(a, p);
    int pb = find_parent(b, p);
    
    if(pa == pb)
        return false;
    
    p[pb] = pa;
    return true;
}

int Solution::solve(int A, vector<vector<int> > &B) 
{
    int ans = 0;
    sort(B.begin(), B.end(), cmp);
    
    int p[A+1];
    for(int i = 0; i <= A; ++i)
        p[i] = i;
    
    for(int i = 0; i < B.size(); ++i)
        if(union_set(B[i][0], B[i][1], p))
            ans += B[i][2];
    
    return ans;
}
