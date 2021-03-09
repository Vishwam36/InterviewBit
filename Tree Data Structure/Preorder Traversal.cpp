// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/preorder-traversal/
// Good 
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
vector<int> Solution::preorderTraversal(TreeNode* root) 
{
    vector<int> ans;
    
    if(root == NULL)
        return ans;
    
    stack<TreeNode*> s;
    s.push(root);
    
    ans.push_back(root -> val);
    
    TreeNode* curr = root -> left;
    
    while(!s.empty() || curr != NULL)
    {
        while(curr != NULL)
        {
            ans.push_back(curr -> val);
            s.push(curr);
            curr = curr -> left;
        }
        curr = s.top() -> right;
        s.pop();
    }
    return ans;
}

// App 2:

/**
 * use stack of pair
 * pair = {node, visit status}
 * if status = 0 then both left and right children are not visited
 * if status = 1 then left child is visited
 * if status = 2 then both are visited
*/

vector<int> Solution::preorderTraversal(TreeNode* root) 
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
            ans.push_back(curr -> val);
            
            s.top().second++;
            if(curr -> left != NULL)
                s.push({curr -> left, 0});
        }
        else if(s.top().second == 1)
        {
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
