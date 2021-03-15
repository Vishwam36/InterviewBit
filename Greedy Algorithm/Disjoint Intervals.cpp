// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/disjoint-intervals/
// Easy 

bool cmp(vector<int> &v1, vector<int> &v2)
{
    if(v1[1] == v2[1])
        return v1[0] < v2[0];
    return v1[1] < v2[1];
}

int Solution::solve(vector<vector<int> > &v) 
{
    sort(v.begin(), v.end(), cmp);
    
    int ans = 1, last = v[0][1];
    
    for(int i = 1; i < v.size(); ++i)
    {
        if(v[i][0] > last)
        {
            ans++;
            last = v[i][1];
        }
    }
    return ans;
}
