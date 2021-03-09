// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/cousins-in-binary-tree/
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

/**
 * pair<pair<node, parent of node>, level of node>
 * queue q1 will do level order traversal
 * queue q2 will store all te nodes travelled
 * we will store values of noded of required level except children of parent which is not required
**/

vector<int> Solution::solve(TreeNode* root, int B) 
{
    vector<int> ans;
    
    if(root == NULL || root -> val == B)
        return ans;
    
    queue<pair<pair<TreeNode*, TreeNode*>, int> > q1, q2;
    q1.push({ {root, NULL}, 0});
    q2.push({ {root, NULL}, 0});
    
    pair<pair<TreeNode*, TreeNode*>, int> p;
    
    int reqLevel = INT_MAX;
    TreeNode* notReqParent;
    
    while(!q1.empty() && q1.front().second <= reqLevel)
    {
        p = q1.front();
        
        if(p.first.first -> left != NULL)
        {
            q1.push({ {p.first.first -> left, p.first.first}, p.second+1});
            q2.push({ {p.first.first -> left, p.first.first}, p.second+1});
            
            if(p.first.first -> left -> val == B)
                notReqParent = p.first.first;
        }
        if(p.first.first -> right != NULL)
        {
            q1.push({ {p.first.first -> right, p.first.first}, p.second+1});
            q2.push({ {p.first.first -> right, p.first.first}, p.second+1});
            
            if(p.first.first -> right -> val == B)
                notReqParent = p.first.first;
        }
        
        if(p.first.first -> val == B)
            reqLevel = p.second;
        
        q1.pop();
    }
    
    while(!q2.empty())
    {
        if(q2.front().second == reqLevel && q2.front().first.second != notReqParent)
            ans.push_back(q2.front().first.first -> val);
        
        q2.pop();
    }
    return ans;
}
