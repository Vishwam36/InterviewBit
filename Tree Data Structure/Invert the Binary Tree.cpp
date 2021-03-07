// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/invert-the-binary-tree/
// Easy

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* Solution::invertTree(TreeNode* root) 
{
    if(root == NULL)
        return root;
        
    TreeNode* temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
    
    root -> left = invertTree(root -> left);
    root -> right = invertTree(root -> right);
    
    return root;
}
