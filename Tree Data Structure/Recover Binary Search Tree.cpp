// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/recover-binary-search-tree/
// Decent
// REF : https://www.youtube.com/watch?v=HsSSUSckMns&t=1061s

/*
Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

    Note:
    A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 

Example :
Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST          
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


TreeNode* first, *second, *pre;

void inorder(TreeNode* root)
{
    if(!root)
        return;
    
    inorder(root->left);
    
    if(pre && !first && root->val < pre->val)
        first = pre;
    if(pre && root->val < pre->val)
        second = root;
    pre = root;
    
    inorder(root->right);
}

vector<int> Solution::recoverTree(TreeNode* root) 
{
    first = NULL, second = NULL, pre = NULL;
    inorder(root);
    return vector<int>({min(first->val, second->val), max(first->val, second->val)});
}
