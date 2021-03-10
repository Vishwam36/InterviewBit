// By vishwam Shriram Mundada
// https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
// Decent

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int preIndex = 0;

int find(int x, vector<int> &v, int start, int end)
{
    for(int i = start; i <= end; ++i)
        if(v[i] == x)
            return i;
}

TreeNode* build(vector<int> &pre, vector<int> &in, int i, int j)
{
    if(i > j || preIndex >= pre.size())
        return NULL;
        
    TreeNode* newNode = new TreeNode(pre[preIndex]);
    
    int index = find(pre[preIndex], in, i, j);
    
    preIndex++;
    
    newNode -> left = build(pre, in, i, index-1);
    newNode -> right = build(pre, in, index+1, j);
    
    return newNode;
}

TreeNode* Solution::buildTree(vector<int> &pre, vector<int> &in) 
{
    preIndex = 0;
    return build(pre, in, 0, in.size()-1);
}
