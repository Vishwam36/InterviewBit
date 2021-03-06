// By vishwam Shriram Mundada
// https://www.interviewbit.com/problems/valid-bst-from-preorder/
// V.Good Problem

int Solution::solve(vector<int> &A) 
{
    stack<int> s;
    int root = INT_MIN;
    
    for(int i = 0; i < A.size(); ++i)
    {
        while(!s.empty() && A[i] > s.top())
        {
            root = s.top();
            s.pop();
        }
        
        if(root > A[i])
            return 0;
            
        s.push(A[i]);
    }
    return 1;
}
