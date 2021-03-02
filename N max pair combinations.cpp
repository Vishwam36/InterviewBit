// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/n-max-pair-combinations/
// Good question

typedef pair<int, pair<int, int> > pipi;

vector<int> Solution::solve(vector<int> &A, vector<int> &B) 
{
    vector<int> ans;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int n = A.size();
    
    set<pair<int, int> > s;
    priority_queue<pipi> pq;
    
    int e1 = n-1, e2 = n-1;
    pq.push(make_pair(A[e1] + B[e2], make_pair(e1, e2)));
    s.insert(make_pair(e1, e2));
    
    int t = n;
    while(t--)
    {
        pipi p = pq.top();
        pq.pop();
        ans.push_back(p.first);
        e1 = p.second.first;
        e2 = p.second.second;
        
        if(e1-1 >= 0 && e2 >= 0 && (s.find(make_pair(e1-1,e2)) == s.end()))
        {
            s.insert(make_pair(e1-1, e2));
            pq.push(make_pair(A[e1-1] + B[e2], make_pair(e1-1, e2)));
        }
        
        if(e1 >= 0 && e2-1 >= 0 && (s.find(make_pair(e1,e2-1)) == s.end()))
        {
            s.insert(make_pair(e1, e2-1));
            pq.push(make_pair(A[e1] + B[e2-1], make_pair(e1, e2-1)));
        }
    }
    return ans;
}
