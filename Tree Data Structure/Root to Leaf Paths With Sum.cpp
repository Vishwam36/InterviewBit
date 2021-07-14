// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/root-to-leaf-paths-with-sum/
// Easy

/*
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]
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

vector<vector<int> > ans;

void rec(TreeNode* root, int tempSum, int sum, vector<int> &temp)
{
    if(!root)
        return;
    
    if(!root->left && !root->right)
    {
        if(tempSum + root->val == sum)
        {
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
        }
        return;
    }
    
    temp.push_back(root->val);
    
    if(root->left)
        rec(root->left, tempSum + root->val, sum, temp);
    
    if(root->right)
        rec(root->right, tempSum + root->val, sum, temp);
    
    temp.pop_back();
}

vector<vector<int> > Solution::pathSum(TreeNode* root, int sum)
{
    ans.clear();
    vector<int> temp;
    rec(root, 0, sum, temp);
    return ans;
}
