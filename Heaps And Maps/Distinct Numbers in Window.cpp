// By Vishwam shriram Mundada
// https://www.interviewbit.com/problems/distinct-numbers-in-window/
// Simple question

vector<int> Solution::dNums(vector<int> &A, int B) 
{
    vector<int> ans;
    int n = A.size(), last = 0;
    
    if(B > n)
        return ans;
        
    unordered_map<int, int> m;
    for(int j = 0; j < B; ++j)
        m[A[j]]++;
    
    ans.push_back(m.size());
    
    for(int i = 1; i+B-1 < n; ++i)
    {
        last = A[i-1];
        m[last]--;
        
        if(m[last] == 0)
            m.erase(m.find(last));
        
        m[A[i+B-1]]++;
        ans.push_back(m.size());
    }
    return ans;
}
