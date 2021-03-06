// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/balanced-binary-tree/
// Simple

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int height(TreeNode* root)
{
    if(root == NULL)
        return 0;
        
    return 1 + max(height(root -> left), height(root -> right));
}

int Solution::isBalanced(TreeNode* root) 
{
    if(root == NULL)
        return 1;
        
    int lHeight = height(root -> left);
    int rHeight = height(root -> right);
    
    int diff = abs(lHeight - rHeight);
    
    if(diff > 1)
        return 0;
    else
        return isBalanced(root -> left) && isBalanced(root -> right);
}
