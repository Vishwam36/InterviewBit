// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/inorder-traversal/
// Good question, recursion not allowed
// Ref : https://www.youtube.com/watch?v=5y_j0OqD7v8&t=346s
// App 2 is easier

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
vector<int> Solution::inorderTraversal(TreeNode* root) 
{
    vector<int> ans;
    
    if(root == NULL) return ans;
    
    stack<TreeNode* > s;
    s.push(root);
    
    TreeNode* curr = root -> left;
    
    while(!s.empty() || curr != NULL)
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr -> left;
        }
        ans.push_back(s.top() -> val);
        curr = s.top() -> right;
        s.pop();
    }
    
    return ans;
}

// App 2:
vector<int> Solution::inorderTraversal(TreeNode* root) 
{
    vector<int> ans;
    
    if(root == NULL)
        return ans;
        
    stack<pair<TreeNode*, int> > s;
    s.push({root,0});
    
    TreeNode* curr;

    while(!s.empty())
    {
        curr = s.top().first;
        
        if(s.top().second == 0)
        {
            s.top().second++;
            if(curr -> left != NULL)
                s.push({curr -> left, 0});
        }
        else if(s.top().second == 1)
        {
            ans.push_back(curr -> val);
            
            s.top().second++;
            if(curr -> right != NULL)
                s.push({curr -> right, 0});
        }
        else
        {
            s.pop();
        }
    }
    return ans;
}
