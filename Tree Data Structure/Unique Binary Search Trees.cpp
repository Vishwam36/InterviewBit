// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/unique-binary-search-trees/
// Good question, difficult to visualize

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<TreeNode*> rec(int st, int end)
{
    vector<TreeNode*> v;
    if(st > end)
    {
        v.push_back(NULL);
        return v;
    }
    if(st == end)
    {
        v.push_back(new TreeNode(st));
        return v;
    }
    
    for(int i = st; i <= end; ++i)
    {
        vector<TreeNode*> lv = rec(st, i-1);
        vector<TreeNode*> rv = rec(i+1, end);
        
        for(auto l : lv)
        {
            for(auto r : rv)
            {
                TreeNode* root = new TreeNode(i);
                
                root -> left = l;
                root -> right = r;
                
                v.push_back(root);
            }
        }
    }
    return v;
}

vector<TreeNode*> Solution::generateTrees(int n)
{
    vector<TreeNode*> ans;
    ans = rec(1, n);
    return ans;
}
