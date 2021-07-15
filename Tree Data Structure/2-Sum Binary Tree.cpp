// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/2sum-binary-tree/
// Good question

/*
Given a binary search tree T, where each node contains a positive integer, and an integer K,
you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes
    Your solution should run in linear time and not take memory more than O(height of T).
    Assume all values in BST are distinct.

Example :
Input 1: 

T :       10
         / \
        9   20

K = 19
Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40
Return: 0
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

// Implement 2 pointers in BST

int Solution::t2Sum(TreeNode* root, int sum) 
{
    stack<TreeNode*> left;
    stack<TreeNode*> right;
    
    TreeNode* temp = root;
    while(temp)
    {
        left.push(temp);
        temp = temp->left;
    }
    
    temp = root;
    while(temp)
    {
        right.push(temp);
        temp = temp->right;
    }
    
    while(!left.empty() && !right.empty())
    {
        TreeNode* l = left.top();
        TreeNode* r = right.top();
        
        if(l != r && l->val + r->val == sum)
            return true;
        
        if(l->val + r->val < sum)
        {
            left.pop();
            if(l->right)
            {
                l = l->right;
                while(l)
                {
                    left.push(l);
                    l = l->left;
                }
            }
        }
        else
        {
            right.pop();
            if(r->left)
            {
                r = r->left;
                while(r)
                {
                    right.push(r);
                    r = r->right;
                }
            }
        }
    }
    return false;
}
