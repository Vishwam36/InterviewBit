// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/evaluate-expression/
// Just need to know "Reverse Polish Notation". Implementation is easy
// Refer : https://www.techopedia.com/definition/9194/reverse-polish-notation-rpn

bool isOperator(string s)
{
    if(s == "+" || s == "-" || s == "/" || s == "*")
        return true;
    
    return false;
}

int operation(int a, int b, string op)
{
    if(op == "+")
        return a + b;
    if(op == "-")
        return a - b;
    if(op == "*")
        return a * b;
    if(op == "/")
        return a / b;
}

int Solution::evalRPN(vector<string> &A) 
{
    int n = A.size();
    int ans = 0;
    stack<string> s;
    for(int i = 0; i < n; ++i)
    {
        if(isOperator(A[i]))
        {
            int op1 = stoi(s.top());
            s.pop();
            int op2 = stoi(s.top());
            s.pop();
            s.push(to_string(operation(op2, op1, A[i])));
        }
        else
        {
            s.push(A[i]);
        }
    }
    return stoi(s.top());
}
