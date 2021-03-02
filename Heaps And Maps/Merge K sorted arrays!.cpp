// By Vishwam Shriram Mudada
// https://www.interviewbit.com/problems/merge-k-sorted-arrays/
// decent

typedef pair<int, pair<int, int> > pi;

vector<int> Solution::solve(vector<vector<int> > &A) 
{
    vector<int> ans;
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    
    for(int i = 0; i < A.size(); ++i)
        pq.push( {A[i][0], {i,0}} );
    
    while(!pq.empty())
    {
        ans.push_back(pq.top().first);
        
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        
        pq.pop();
        
        if(j < A[0].size() - 1)
            pq.push( {A[i][j+1], {i,j+1}} );
    }
    return ans;
}
