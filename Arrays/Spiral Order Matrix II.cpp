// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/spiral-order-matrix-ii/
// Easy go if you know spiral traversing

vector<vector<int> > Solution::generateMatrix(int n) 
{
    int l = 0, r = n-1, t = 0, b = n-1, k = 1;
    vector<vector<int> > ans(n, vector<int> (n, 0));
    
    while(l <= r && t <= b)
    {
        for(int i = l; i <= r; ++i)
            ans[t][i] = k++;
        
        ++t;
        
        for(int i = t; i <= b; ++i)
            ans[i][r] = k++;
        
        --r;

        for(int i = r; i >= l; --i)
            ans[b][i] = k++;
        
        --b;
        
        for(int i = b; i >= t; --i)
            ans[i][l] = k++;
        
        ++l;
    }
    
    return ans;
}
