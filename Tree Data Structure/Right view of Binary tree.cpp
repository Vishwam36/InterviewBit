// By vishwam Shriram Mundada
// https://www.interviewbit.com/problems/right-view-of-binary-tree/
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

vector<int> Solution::solve(TreeNode* root) 
{
    vector<int> ans;
    
    if(root == NULL)
        return ans;
        
    queue<pair<TreeNode*, int> > q; // second element of pair is the level of node
    q.push({root, 0});
    
    pair<TreeNode*, int> p;
    
    while(!q.empty())
    {
        int level = q.front().second;
        
        // Pop till we find rightmost/last node of that level
        while(q.front().second == level && !q.empty())
        {
            p = q.front();
            if(p.first -> left != NULL)
                q.push({p.first -> left, level+1});
        
            if(p.first -> right != NULL) 
                q.push({p.first -> right, level+1});
            
            q.pop();
        }
        ans.push_back(p.first -> val);
    }
    return ans;
}
