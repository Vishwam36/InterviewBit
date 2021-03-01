// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/palindrome-partitioning/
// Decent

bool isPalindrome(string s, int i, int j)
{
    while(i < j)
    {
        if(s[i] != s[j])
            return false;
    
        ++i;
        --j;
    }
    
    return true;
}

void rec(string A, vector<vector<string> > &ans, vector<string> temp)
{
    if(A.size() == 0)
    {
        ans.push_back(temp);
        return;
    }
    
    for(int i = 0; i < A.size(); ++i)
    {
        if(isPalindrome(A, 0, i))
        {
            temp.push_back(A.substr(0, i+1));
            string newA = A.substr(i+1, A.size());
            rec(newA, ans, temp);
            temp.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A)
{
    vector<vector<string> > ans;
    vector<string> temp;
    rec(A, ans, temp);
    return ans;
}
