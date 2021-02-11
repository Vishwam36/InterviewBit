// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/two-out-of-three/
// simple

vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) 
{
    vector<int> ans;
    map<int, tuple<bool, bool, bool>> m;
    map<int, tuple<bool, bool, bool>> :: iterator it;
    
    for(int i = 0; i < A.size(); ++i)
    {
        get<0>(m[A[i]]) = true;
    }
    for(int i = 0; i < B.size(); ++i)
    {
        get<1>(m[B[i]]) = true;
    }
    for(int i = 0; i < C.size(); ++i)
    {
        get<2>(m[C[i]]) = true;
    }
    
    for(it = m.begin(); it != m.end(); ++it)
    {
        int temp = 0;
        if(get<0>(it -> second) == true)
            temp++;
        
        if(get<1>(it -> second) == true)
            temp++;
        
        if(get<2>(it -> second) == true)
            temp++;
        
        if(temp >= 2)
            ans.push_back(it -> first);
    }
    return ans;
}
