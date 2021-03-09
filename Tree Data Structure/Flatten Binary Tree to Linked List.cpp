// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
// Decent

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void flattenUtil(TreeNode* root)
{
    if(root == NULL)
        return;
        
    if(root -> left == NULL && root -> right == NULL)
        return;
        
    if(root -> left != NULL)
    {
        TreeNode* temp1 = root -> right;
        root -> right = root -> left;
        root -> left = NULL;
        
        TreeNode* temp2 = root -> right;
        
        while(temp2 -> right != NULL)
            temp2 = temp2 -> right;
        
        temp2 -> right = temp1;
    }
    flattenUtil(root -> right);
}

TreeNode* Solution::flatten(TreeNode* root)
{
    flattenUtil(root);
    return root;
}
