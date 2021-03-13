// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/assign-mice-to-holes/
// Easy

int Solution::mice(vector<int> &A, vector<int> &B) 
{
    int ans = 0, n = A.size();
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for(int i = 0; i < n; ++i)
        ans = max(ans, abs(A[i]-B[i]));
    
    return ans;
}
