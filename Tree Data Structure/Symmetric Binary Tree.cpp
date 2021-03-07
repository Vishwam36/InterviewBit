// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/symmetric-binary-tree/
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
 
bool util(TreeNode* rootLeft, TreeNode* rootRight)
{
    if(rootLeft == NULL && rootRight == NULL) return true;
    
    if(rootLeft == NULL) return false;
    if(rootRight == NULL) return false;
    
    if(rootLeft -> val == rootRight -> val)
    {
        bool l = util(rootLeft -> left, rootRight -> right);
        bool r = util(rootLeft -> right, rootRight -> left);
        return l && r;
    }
    else
    {
        return false;
    }
}

int Solution::isSymmetric(TreeNode* root) 
{
    if(root == NULL) return 1;
    return util(root -> left, root -> right);
}
