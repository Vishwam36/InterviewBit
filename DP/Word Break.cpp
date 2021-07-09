// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/word-break/
// Decent. 2 approaches

/*
Given a string A and a dictionary of words B, determine if A can be segmented into a space-separated sequence of one or more dictionary words.

Input Format:
The first argument is a string, A.
The second argument is an array of strings, B.

Output Format:
Return 0 / 1 ( 0 for false, 1 for true ) for this problem.

Constraints:
1 <= len(A) <= 6500
1 <= len(B) <= 10000
1 <= len(B[i]) <= 20

Examples:
Input 1:
    A = "myinterviewtrainer",
    B = ["trainer", "my", "interview"]
Output 1:
    1
Explanation 1:
    Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented as "my interview trainer".
    
Input 2:
    A = "a"
    B = ["aaa"]
Output 2:
    0
Explanation 2:
    Return 0 ( corresponding to false ) because "a" cannot be segmented as "aaa".
*/


// App 1 :

int dp[6501];

bool rec(int idx, string s, vector<string> &dict)
{
    if(dp[idx] != -1)
        return dp[idx];
    
    for(int sz = 1; sz <= s.size(); ++sz)
    {
        bool flag = 0;
        string match = s.substr(0, sz);
        for(auto &word : dict)
        {
            if(word == match)
            {
                flag = 1;
                break;
            }
        }
        if(flag && rec(idx+sz, s.substr(sz), dict))
            return dp[idx] = 1;
    }
    return dp[idx] = 0;
}

int Solution::wordBreak(string A, vector<string> &B) 
{
    memset(dp, -1, sizeof(dp));
    dp[A.size()] = 1;
    return rec(0, A, B);
}


// App 2 : 
// Trie solution

struct Node
{
    bool isLeaf;
    Node* children[26];
};

Node* globalRoot;

void insert(Node* root, string s)
{
    for(auto ch : s)
    {
        if(!root->children[ch-'a'])
            root->children[ch-'a'] = new Node();
        
        root = root->children[ch-'a'];
    }
    root->isLeaf = true;
}

int dp[6501];

bool rec(int idx, string &s, Node* root)
{
    if(idx == s.size())
        return true;
    
    if(dp[idx] != -1)
        return dp[idx];
    
    bool ans = false;
    for(int i = idx; i < s.size(); ++i)
    {
        if(root->children[s[i]-'a'])
        {
            root = root->children[s[i]-'a'];
            
            if(root->isLeaf)
                ans = ans || rec(i+1, s, globalRoot);
        }
        else
        {
            break;
        }
    }
    return dp[idx] = ans;
}

int Solution::wordBreak(string A, vector<string> &B) 
{
    Node* root = new Node();
    for(auto s : B)
        insert(root, s);
    
    memset(dp, -1, sizeof(dp));
    globalRoot = root;
    return rec(0, A, globalRoot);
}
