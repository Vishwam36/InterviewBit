// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/valid-binary-search-tree/
// Easy
// Define range for every node (min, max)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool valid(TreeNode* root, long minLimit, long maxLimit)
{
    if(root == NULL)
        return true;
        
    if(root -> val > minLimit && root -> val < maxLimit)
        return valid(root -> left, minLimit, root -> val) 
               && valid(root -> right, root -> val, maxLimit);
    
    else
        return false;
}

int Solution::isValidBST(TreeNode* root) 
{
    if(valid(root, LLONG_MIN, LLONG_MAX)) 
        return 1;
    
    return 0;
}
