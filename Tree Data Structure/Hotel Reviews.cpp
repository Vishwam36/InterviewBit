// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/hotel-reviews/
// Trie approach is new

// App 1: normal one

bool cmp(const pair<int, int> &p, const pair<int, int> &q)
{
    if(p.first == q.first)
        return p.second < q.second;
    
    return p.first > q.first;
}

vector<int> Solution::solve(string A, vector<string> &B) 
{
    unordered_set<string> good;
    for(int i = 0; i < A.size(); ++i)
    {
        string s;
        while(A[i] != '_' && i < A.size())
        {
            s.push_back(A[i]);
            ++i;
        }
        good.insert(s);
    }
    
    vector<pair<int,int> > v;
    for(int i = 0; i < B.size(); ++i)
    {
        int count = 0;
        string review = B[i];
        for(int j = 0; j < review.size(); ++j)
        {
            string s;
            while(review[j] != '_' && j < review.size())
            {
                s.push_back(review[j]);
                ++j;
            }
            if(good.find(s) != good.end())
            {
                count++;
            }
        }
        v.push_back({count, i});
    }
    sort(v.begin(), v.end(), cmp);
    
    vector<int> ans;
    for(int i = 0; i < v.size(); ++i)
        ans.push_back(v[i].second);
    
    return ans;
}

// App 2: Trie data structure

struct trie
{
    bool isLeaf;
    trie *child[26];
};

trie* newNode()
{
    trie* node = new trie();
    node -> isLeaf = 0;
    for(int i = 0; i < 26; ++i)
        node -> child[i] = NULL;
    
    return node;
}

void insert(trie* root, string s)
{
    for(int i = 0; i < s.size(); ++i)
    {
        if(root -> child[s[i]-'a'] != NULL)
            root = root -> child[s[i]-'a'];
        
        else
        {
            trie* node = newNode();
            root -> child[s[i]-'a'] = node;
            root = root -> child[s[i]-'a'];
        }
    }
    root -> isLeaf = 1;
}

bool find(trie* root, string s)
{
    for(int i = 0; i < s.size(); ++i)
    {
        if(root -> child[s[i]-'a'] == NULL)
            return 0;
        
        root = root -> child[s[i]-'a'];
    }
    return root && root -> isLeaf;
}

bool cmp(const pair<int, int> &p, const pair<int, int> &q)
{
    if(p.first == q.first)
        return p.second < q.second;
    
    return p.first > q.first;
}

vector<int> Solution::solve(string A, vector<string> &B) 
{
    trie* root = newNode();
    
    for(int i = 0; i < A.size(); ++i)
    {
        string s;
        while(A[i] != '_' && i < A.size())
        {
            s.push_back(A[i]);
            ++i;
        }
        insert(root, s);
    }
    
    vector<pair<int, int> > v;
    for(int i = 0; i < B.size(); ++i)
    {
        string review = B[i];
        int count = 0;
        for(int j = 0; j < review.size(); ++j)
        {
            string s;
            while(review[j] != '_' && j < review.size())
            {
                s.push_back(review[j]);
                j++;
            }
            if(find(root, s))
            {
                count++;
            }
        }
        v.push_back({count, i});
    }
    sort(v.begin(), v.end(), cmp);
    
    vector<int> ans;
    for(int i = 0; i < v.size(); ++i)
        ans.push_back(v[i].second);
    
    return ans;
}
