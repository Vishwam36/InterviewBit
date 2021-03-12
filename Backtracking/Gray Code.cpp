// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/gray-code/
// Decent

vector<int> Solution::grayCode(int n)
{
    vector<int> ans;
    ans.push_back(0);
    
    if(n == 0)
        return ans;
    
    for(int i = 0; i < n; ++i)
    {
        int l = ans.size();
        for(int j = l-1; j >= 0; --j)
            ans.push_back((1 << i) + ans[j]);
    }
    
    return ans;
}
