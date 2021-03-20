// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/maximum-level-sum/
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

int Solution::solve(TreeNode* root) 
{
    queue<pair<TreeNode*, int> > q;
    q.push({root, 0});
    
    int maxSum = INT_MIN, sum = 0, i = 0;
    
    while(!q.empty())
    {
        pair<TreeNode*, int> temp = q.front();
        q.pop();
        
        if(i != temp.second)
        {
            sum = 0;
            ++i;
        }
        
        sum += temp.first -> val;
        maxSum = max(maxSum, sum);
        
        if(temp.first -> left != NULL)
            q.push({temp.first -> left, temp.second+1});
        
        if(temp.first -> right)
            q.push({temp.first -> right, temp.second+1});
    }
    
    return maxSum;
}
