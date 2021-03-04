// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/next-greater-number-bst/
// Decent, important
// Commonly known as inorder successor in BST 
// Ref : https://www.youtube.com/watch?v=5cPbNCrdotA&feature=youtu.be&ab_channel=mycodeschool

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* findMin(TreeNode* root)
{
    while(root -> left != NULL)
        root = root -> left;
        
    return root;
}

TreeNode* find(TreeNode* root, int b)
{
    if(root == NULL)
        return NULL;
        
    if(b == root -> val)
        return root;
    
    else if(b <= root -> val)
        return find(root -> left, b);
    
    else
        return find(root -> right, b);
}

TreeNode* Solution::getSuccessor(TreeNode* root, int b)
{
    TreeNode* givenNode = find(root, b);
    
    if(givenNode == NULL)
        return root;
        
    if(givenNode -> right != NULL)
        return findMin(givenNode -> right);
        
    TreeNode* next = NULL;
    while(root -> val != b)
    {
        if(b < root -> val)
        {
            next = root;
            root = root -> left;
        }
        else
        {
            root = root -> right;
        }
    }
    return next;
}
