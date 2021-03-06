// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/min-depth-of-binary-tree/
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


int Solution::minDepth(TreeNode* root) 
{
    if(root == NULL) return 0;
    
    int minL = minDepth(root -> left);
    int minR = minDepth(root -> right);
    
    if(minL == 0) return minR+1;
    if(minR == 0) return minL+1;
    
    return min(minL, minR) + 1;
}
