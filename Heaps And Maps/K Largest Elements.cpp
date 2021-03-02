// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/k-largest-elements/
// Basic, easy

vector<int> Solution::solve(vector<int> &A, int B) 
{
    priority_queue<int, vetcor<int>, greater<int> > pq;
    
    for(int i = 0; i < A.size(); ++i)
    {
        pq.push(A[i]);
        
        if(pq.size() > B)
            pq.pop();
    }
    
    vector<int> ans;
    while(pq.size())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
