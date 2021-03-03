// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/pascal-triangle/
// Simple

vector<vector<int> > Solution::solve(int A) 
{
    vector<vector<int> > ans;
    
    for(int i = 0; i < A; ++i)
    {
        vector<int> temp;
        int n = 1;
        
        for(int j = 0; j <= i; ++j)
        {
            temp.push_back(n);
            n = (n * (i-j))/(j+1);
        }
        
        ans.push_back(temp);
    }
    
    return ans;
}
