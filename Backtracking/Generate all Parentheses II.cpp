// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/generate-all-parentheses-ii/
// Decent 

void rec(vector<string> &ans, string temp, int nOpen, int nClose, int n)
{
    if(temp.size() == 2*n)
    {
        ans.push_back(temp);
        return;
    }
    
    if(nOpen < n)
    {
        temp += "(";
        rec(ans, temp, nOpen+1, nClose, n);
        temp.pop_back();
    }
    if(nOpen > nClose)
    {
        temp += ")";
        rec(ans, temp, nOpen, nClose+1, n);
        temp.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int n)
{
    vector<string> ans;
    string temp;
    rec(ans, temp, 0, 0, n);
    return ans;
}
