// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/sum-root-to-leaf-numbers/
// Easy

/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers % 1003.

Example :
    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.
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

int ans;
int MOD = 1003;

void rec(TreeNode* root, int sum)
{
    sum = (sum*10 + root->val) % MOD;
    if(!root->left && !root->right)
    {
        ans += sum;
        ans %= MOD;
        return;
    }
    if(root->left)
        rec(root->left, sum);
    if(root->right)
        rec(root->right, sum);
}

int Solution::sumNumbers(TreeNode* root) 
{
    ans = 0;
    rec(root, 0);
    return ans;
}
