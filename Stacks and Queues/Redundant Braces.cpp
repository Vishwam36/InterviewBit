// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/redundant-braces/
// Simple 

int Solution::braces(string A)
{
    int i = 0;
    stack<char> s;
    
    while(i < A.size())
    {
        if(A[i] == '(' || A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/')
            s.push(A[i]);
            
        if(A[i] == ')')
        {
            if(s.top() == '(')
                return 1;
                
            while(s.top() != '(')
                s.pop();
                
            s.pop();
        }
        ++i;
    }
    return 0;
}
