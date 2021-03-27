// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/level-order/
// Simple Trees Question

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* root) 
{
    vector<vector<int> > ans;
    map<int, vector<int> > m;
    
    queue<pair<TreeNode*, int> > q;
    q.push({root, 0});
    
    while(!q.empty())
    {
        pair<TreeNode*, int> p = q.front();
        q.pop();
        
        m[p.second].push_back(p.first -> val);
        
        if(p.first -> left != NULL)
            q.push({p.first -> left, p.second+1});
        
        if(p.first -> right != NULL)
            q.push({p.first -> right, p.second+1});
    }
    
    for(auto i = m.begin(); i != m.end(); ++i)
        ans.push_back(i -> second);
    
    return ans;
}
