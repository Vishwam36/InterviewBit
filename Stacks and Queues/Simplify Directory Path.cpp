// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/simplify-directory-path/
// too many conditions

string Solution::simplifyPath(string A) 
{
    string ans = "";
    string temp = "";
    int n = A.size();
    stack<string> s;
    vector<string> v;
    for(int i = 0; i < n; ++i)
    {
        if(A[i] == '/')
        {
            if(temp.size() > 0)
            {
                v.push_back(temp);
            }
            temp = "";
            continue;
        }
        else
        {
            temp += A[i];
        }
    }
    if(temp.size() > 0)
    {
        v.push_back(temp);
    }
    for(int i = 0; i < v.size(); ++i)
    {
        if(v[i] == ".")
        {
            continue;
        }
        else if(v[i] == "..")
        {
            if(!s.empty())
            {
                s.pop();
            }
        }
        else
        {
            s.push(v[i]);
        }
    }
    
    while(!s.empty())
    {
        reverse(s.top().begin(), s.top().end());
        ans += s.top();
        ans += "/";
        s.pop();
    }
    if(ans.size() == 0)
    {
        ans += "/";
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
