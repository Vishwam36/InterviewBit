// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/inorder-traversal/
// Good question, recursion not allowed
// Ref : https://www.youtube.com/watch?v=5y_j0OqD7v8&t=346s

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> Solution::inorderTraversal(TreeNode* root) 
{
    vector<int> ans;
    
    if(root == NULL) return ans;
    
    stack<TreeNode* > s;
    s.push(root);
    
    TreeNode* curr = root -> left;
    
    while(!s.empty() || curr != NULL)
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr -> left;
        }
        ans.push_back(s.top() -> val);
        curr = s.top() -> right;
        s.pop();
    }
    
    return ans;
}
