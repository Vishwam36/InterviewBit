// By Vishwam Shriram mundada
// https://www.interviewbit.com/problems/letter-phone/
// Good but basic

vector<string> v;

void initialize()
{
    v.push_back("0");
    v.push_back("1");
    v.push_back("abc");
    v.push_back("def");
    v.push_back("ghi");
    v.push_back("jkl");
    v.push_back("mno");
    v.push_back("pqrs");
    v.push_back("tuv");
    v.push_back("wxyz");
}

void rec(string A, int index, vector<string> &ans, string temp)
{
    if(index >= A.size())
        return;
        
    string chars = v[A[index]-'0'];
    for(int i = 0; i < chars.size(); ++i)
    {
        temp.push_back(chars[i]);
        
        if(temp.size() == A.size())
            ans.push_back(temp);
            
        else
            rec(A, index+1, ans, temp);
            
        temp.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) 
{
    initialize();
    vector<string> ans;
    string temp = "";
    
    rec(A, 0, ans, temp);
    
    return ans;
}
