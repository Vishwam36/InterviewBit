// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/meeting-rooms/
// Decent

// App 1:
int Solution::solve(vector<vector<int> > &A) 
{
    sort(A.begin(), A.end());
    
    int ans = 1;
    
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(A[0][1]);
    
    for(int i = 1; i < A.size(); ++i)
    {
        if(A[i][0] < pq.top())
            ++ans;
        
        else
            pq.pop();
        
        pq.push(A[i][1]);
    }
    return ans;
}


// App 2:
int Solution::solve(vector<vector<int> > &A) 
{
    int ans = 0, n = A.size();
    
    vector<int> v1, v2;
    for(int i = 0; i < n; ++i)
    {
        v1.push_back(A[i][0]);
        v2.push_back(A[i][1]);
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    int j = 0, k = 0;
    for(int i = 0; i < n; ++i)
    {
        if(v1[j] < v2[k])
        {
            ++ans;
            ++j;
        }
        else
        {
            ++j;
            ++k;
        }
    }
    return ans;
}
