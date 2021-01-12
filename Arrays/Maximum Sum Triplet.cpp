// By Vishwam Mundada
// https://www.interviewbit.com/problems/maximum-sum-triplet/

long long maxx(long long a, long long b)
{
    if(a > b)
        return a;
    return b;
}

int Solution::solve(vector<int> &A)
{
    long long ans = 0;
    int n = A.size();
    
    vector<int> rightMax(n);
    int max = A[n-1];
    
    rightMax[n-1] = A[n-1];
    for(int i = n-2; i >= 0; --i)
    {
        if(A[i] > max)
        {
            max = A[i];
            rightMax[i] = max;
        }
        else
        {
            rightMax[i] = max;
        }
    }
    
    set<int> s;
    set<int> :: iterator it;
    s.insert(A[0]);
    
    for(int i = 1; i < n-1; ++i)
    {
        if(s.lower_bound(A[i]) != s.begin() && rightMax[i+1] > A[i])
        {
            it = s.lower_bound(A[i]);
            --it;
            
            ans = maxx(ans, *it + rightMax[i+1] + A[i]);
        }
        s.insert(A[i]);
    }
    
    return ans;
}
