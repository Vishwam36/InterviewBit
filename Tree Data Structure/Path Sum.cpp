// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/path-sum/
// Easy

/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool ans;

void rec(TreeNode* root, int sum, int B)
{
    if(!root)
        return;
    
    if(!root->left && !root->right)
    {
        if(sum+root->val == B)
            ans = true;
        return;
    }
    
    rec(root->left, sum+root->val, B);
    rec(root->right, sum+root->val, B);
}

int Solution::hasPathSum(TreeNode* A, int B) 
{
    ans = false;
    rec(A, 0, B);
    return ans;
}
