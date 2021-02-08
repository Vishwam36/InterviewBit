// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/maxspprod/

int Solution::maxSpecialProduct(vector<int> &A) 
{
    int n = A.size();
    int l[n];
    int r[n];
    stack<pair<int, int> > s;
    for(int i = 0; i < n; ++i)
    {
        while(!s.empty() && s.top().first <= A[i])
            s.pop();
            
        if(s.empty())
            l[i] = 0;
        else
            l[i] = s.top().second;
            
        s.push(make_pair(A[i], i));
    }
    
    while(!s.empty())
        s.pop();
    
    for(int i = n-1; i >= 0; --i)
    {
        while(!s.empty() && s.top().first <= A[i])
            s.pop();
            
        if(s.empty())
            r[i] = 0;
        else
            r[i] = s.top().second;
            
        s.push(make_pair(A[i], i));
    }
    
    long long maximum = 0;
    
    for(int i = 0; i < n; ++i)
        if(maximum < (l[i] * 1LL * r[i]))
            maximum = l[i] * 1LL * r[i];
    
    return maximum % 1000000007;
}
