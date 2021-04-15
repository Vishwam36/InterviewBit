// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/shortest-unique-prefix/
// Decent question
// Trie data structure

struct trie
{
    int words;
    trie* child[26];
};

trie* newTrie()
{
    trie* node = new trie();
    for(int i = 0; i < 26; ++i)
        node -> child[i] = NULL;
    
    node -> words = 0;
    return node;
}

void insert(trie* root, string s)
{
    for(int i = 0; i < s.size(); ++i)
    {
        root -> words++;
        int index = s[i]-'a';
        if(root -> child[index] == NULL)
        {
            trie* temp = newTrie();
            root -> child[index] = temp;
        }
        root = root -> child[index];
    }
}

string find(trie* root, string s)
{
    string ans;
    for(int i = 0; i < s.size(); ++i)
    {
        if(root -> child[s[i]-'a'] != NULL && root -> words > 1)
        {
            ans += s[i];
            root = root -> child[s[i]-'a'];
        }
        else
        {
            return ans;
        }
    }
    return ans;
}

vector<string> Solution::prefix(vector<string> &A) 
{
    trie* root = newTrie();
    for(int i = 0; i < A.size(); ++i)
        insert(root, A[i]);
    
    vector<string> ans;
    for(int i = 0; i < A.size(); ++i)
        ans.push_back(find(root, A[i]));
    
    return ans;
}
