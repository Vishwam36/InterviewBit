// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/preorder-traversal/
// Good 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> Solution::preorderTraversal(TreeNode* root) 
{
    vector<int> ans;
    
    if(root == NULL)
        return ans;
    
    stack<TreeNode*> s;
    s.push(root);
    
    ans.push_back(root -> val);
    
    TreeNode* curr = root -> left;
    
    while(!s.empty() || curr != NULL)
    {
        while(curr != NULL)
        {
            ans.push_back(curr -> val);
            s.push(curr);
            curr = curr -> left;
        }
        curr = s.top() -> right;
        s.pop();
    }
    return ans;
}
