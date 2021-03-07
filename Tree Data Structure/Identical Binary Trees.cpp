// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/identical-binary-trees/
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

int Solution::isSameTree(TreeNode* root1, TreeNode* root2) 
{
    if(root1 == NULL && root2 == NULL) return 1;
    
    if(root1 == NULL) return 0;
    if(root2 == NULL) return 0;
    
    if(root1 -> val == root2 -> val)
    {
        int l = isSameTree(root1 -> left, root2 -> left);
        int r = isSameTree(root1 -> right, root2 -> right);
        return l && r;
    }
    else
    {
        return 0;
    }
}
