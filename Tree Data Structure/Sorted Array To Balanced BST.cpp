// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/
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
 
TreeNode* rec(int i, int j, const vector<int> &A)
{
    if(i > j)
        return NULL;
    
    int mid = (i+j)/2;
    
    TreeNode* root = new TreeNode(A[mid]);
    
    root -> left = rec(i, mid-1, A);
    root -> right = rec(mid+1, j, A);
    
    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) 
{
    return rec(0, A.size()-1, A);
}
