// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/word-ladder-ii/
// Decent question

vector<vector<string> > ans;
int minLen = INT_MAX;
string finish;

bool isAdj(string a, string b)
{
    int cnt = 0;
    for(int i = 0; i < a.size(); ++i)
        if(a[i] != b[i])
            ++cnt;
    
    if(cnt == 1)
        return 1;
    
    return 0;
}

void dfs(vector<string> &temp, vector<string> &dict, bool vis[], int len)
{
    if(len > minLen)
        return;
    
    if(temp[len-1] == finish)
    {
        if(len < minLen)
        {
            minLen = len;
            ans.clear();
        }
        ans.push_back(temp);
        return;
    }
    
    string s = temp[len-1];
    for(int i = 0; i < dict.size(); ++i)
    {
        if(!vis[i] && isAdj(s, dict[i]))
        {
            vis[i] = 1;
            temp.push_back(dict[i]);
            dfs(temp, dict, vis, len+1);
            vis[i] = 0;
            temp.pop_back();
        }
    }
}

vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict)
{
    minLen = INT_MAX;
    ans.clear();
    finish = end;
    
    dict.push_back(end);
    
    unordered_set<string> s;
    for(int i = 0; i < dict.size(); ++i)
        s.insert(dict[i]);
    
    dict.assign(s.begin(), s.end());

    vector<string> temp = {start};
    bool vis[dict.size()];
    for(int i = 0; i < dict.size(); ++i)
        vis[i] = 0;
    
    dfs(temp, dict, vis, 1);
    return ans;
}
