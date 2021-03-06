// By vishwam Shriram Mundada
// https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
// Simple inorder

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void inorder(TreeNode* root, vector<int> &v, int k)
{
    if(root == NULL || v.size() >= k)
        return;
        
    inorder(root -> left, v, k);
    v.push_back(root -> val);
    
    if(v.size() >= k)
        return;
    
    inorder(root -> right, v, k);
}

int Solution::kthsmallest(TreeNode* root, int k) 
{
    vector<int> v;
    inorder(root, v, k);
    return v[k-1];
}
