// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/reverse-level-order/
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

// App 1:
vector<int> Solution::solve(TreeNode* root) 
{
    queue<TreeNode*> q;
    q.push(root);
    
    vector<int> ans;
    
    while(!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();
        
        ans.push_back(temp -> val);
        
        if(temp -> right != NULL)
            q.push(temp -> right);
        
        if(temp -> left != NULL)
            q.push(temp -> left);
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

// App 2:
TreeNode* reverse(TreeNode* root)
{
    if(root == NULL)
        return root;
        
    TreeNode* temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
    
    root -> left = reverse(root -> left);
    root -> right = reverse(root -> right);
    
    return root;
}

vector<int> Solution::solve(TreeNode* root) 
{
    root = reverse(root);
    vector<int> ans;
    
    if(root == NULL)
        return ans;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();
        
        ans.push_back(temp -> val);
        
        if(temp -> left != NULL)
            q.push(temp -> left);
        
        if(temp -> right != NULL)
            q.push(temp -> right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
