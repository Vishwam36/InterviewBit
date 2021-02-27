// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/nearest-smaller-element/
// Not difficult but a bit tricky

vector<int> Solution::prevSmaller(vector<int> &A) 
{
    stack<int> s;
    vector<int> G;
    int n = A.size();
    
    G.push_back(-1);
    s.push(A[0]);
            
    for(int i = 1; i < n; ++i)
    {
        if(A[i] > s.top())
        {
            G.push_back(s.top());
            s.push(A[i]);
        }
        else
        {
            while(!s.empty())
            {
                if(s.top() >= A[i])
                    s.pop();
                
                else
                {
                    G.push_back(s.top());
                    s.push(A[i]);
                    break;
                }
            }
            if(s.empty())
            {
                G.push_back(-1);
                s.push(A[i]);
            }
        }
    }
    return G;
}
