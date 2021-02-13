// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/longest-arithmetic-progression/
// Ref : https://www.youtube.com/watch?v=Lm38EAoDc7c&ab_channel=ChirayuJain
// decent
// dp[i][diff] will contain number of elements of AP whose last element is i and common difference is diff

int Solution::solve(const vector<int> &A) 
{
    int n = A.size();
    if(n <= 2)
        return n;
        
    vector<unordered_map<int, int> > dp(n);
    
    int ans = 2;
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            int diff = A[j] - A[i];
            
            // if there is already an AP with CD diff
            if(dp[i].find(diff) != dp[i].end())
            {
                dp[j][diff] = dp[i][diff] + 1;
            }
            
            // if there is no AP with CD diff then we start new with last element A[j]
            else
            {
                dp[j][diff] = 2;
            }
            ans = max(ans, dp[j][diff]);
        }
    }
    return ans;
}
