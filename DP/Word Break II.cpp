// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/word-break-ii/
// Decent
// This is backtracking, not DP

/*
Given a string A and a dictionary of words B, add spaces in A to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

Note : Make sure the strings are sorted in your result.

Input Format:
The first argument is a string, A.
The second argument is an array of strings, B.

Output Format:
Return a vector of strings representing the answer as described in the problem statement.

Constraints:
1 <= len(A) <= 50
1 <= len(B) <= 25
1 <= len(B[i]) <= 20

Examples:
Input 1:
    A = "b"
    B = ["aabbb"]

Output 1:
    []

Input 1:
    A = "catsanddog",
    B = ["cat", "cats", "and", "sand", "dog"]

Output 1:
    ["cat sand dog", "cats and dog"]
*/

struct Node
{
    bool isLeaf;
    Node* children[26];
};

void insert(Node* root, string s)
{
    for(int i = 0; i < s.size(); ++i)
    {
        if(!root->children[s[i]-'a'])
            root->children[s[i]-'a'] = new Node();
        
        root = root->children[s[i]-'a'];
    }
    root->isLeaf = true;
}

Node* globalRoot;
vector<string> ans;

void rec(int idx, string &s, string temp, Node* root)
{
    if(idx == s.size())
    {
        temp.pop_back();
        ans.push_back(temp);
    }
    
    for(int i = idx; i < s.size(); ++i)
    {
        if(root->children[s[i]-'a'])
        {
            temp.push_back(s[i]);
            root = root->children[s[i]-'a'];
            
            if(root->isLeaf)
            {
                temp.push_back(' ');
                rec(i+1, s, temp, globalRoot);
                temp.pop_back();
            }
        }
        else
            break;
    }
    return;
}

vector<string> Solution::wordBreak(string A, vector<string> &B)
{
    ans.clear();
    Node* root = new Node();
    for(auto s : B)
        insert(root, s);
    
    globalRoot = root;
    string temp;
    rec(0, A, temp, globalRoot);
    sort(ans.begin(), ans.end());
    return ans;
}
