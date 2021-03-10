// By vishwam Shriram Mundada
// https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/
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
 
int maxIndex(vector<int> A, int i, int j)
{
    int maxIndex = -1;
    
    for(int k = i; k <= j; ++k)
        if(A[maxIndex] < A[k])
            maxIndex = k;
    
    return maxIndex;
}

TreeNode* build(TreeNode* root, vector<int> v, int i, int j)
{
    if(i > j)
        return NULL;
    
    int index = maxIndex(v, i, j);
    
    if(index == -1)
        return NULL;
    
    TreeNode* newNode = new TreeNode(v[index]);
    
    newNode -> left = build(newNode, v, i, index-1);
    newNode -> right = build(newNode, v, index+1, j);
    
    return newNode;
}

TreeNode* Solution::buildTree(vector<int> &A) 
{
    TreeNode* root;
    root = build(root, A, 0, A.size()-1);
    return root;
}
