// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/path-to-given-node/
// App 2 is good

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// App 1:

int flag = 0;
void rec(TreeNode* root, int B, vector<int> &v)
{
    if(root == NULL || root -> val == -1)
        return;
        
    if(root -> val == B)
    {
        flag = 1; // found the node
        v.push_back(root -> val);
        return;
    }
    
    rec(root -> left, B, v);
    if(flag == 1)
    {
        v.push_back(root -> val);
        return;
    }
    
    rec(root -> right, B, v);
    if(flag == 1)
    {
        v.push_back(root -> val);
        return;
    }
}

vector<int> Solution::solve(TreeNode* root, int B) 
{
    flag = 0;
    vector<int> v;
    rec(root, B, v);
    reverse(v.begin(), v.end());
    return v;
}


// App 2: Good one, write on paper to understand

bool rec(TreeNode* root, int B, vector<int> &v)
{
    if(root == NULL || root -> val == -1)
        return false;
        
    if(rec(root -> left, B, v) || rec(root -> right, B, v) || (root -> val == B)) // B found, keep returning and pushing values in vector
    {
        v.push_back(root -> val);
        return true;
    }
    return false;
}

vector<int> Solution::solve(TreeNode* root, int B) 
{
    vector<int> v;
    rec(root, B, v);
    reverse(v.begin(), v.end());
    return v;
}
