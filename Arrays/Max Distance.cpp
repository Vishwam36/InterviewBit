// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/max-distance/
// Good trick -- try on paper

int Solution::maximumGap(const vector<int> &A) 
{
    int n = A.size();
    vector<pair<int,int> > v;
    for(int i = 0; i < n; ++i)
    {
        v.push_back(make_pair(A[i],i));
    }
    
    sort(v.begin(), v.end());
    
    int ans = 0, j = v[n-1].second;
    
    for(int i = n-2; i >= 0; --i)
    {
        ans = max(ans, j - v[i].second);
        j = max(j, v[i].second);
    }
    
    return ans;
}
