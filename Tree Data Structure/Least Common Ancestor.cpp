// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/least-common-ancestor/
// App 1 is Decent, App 2 is simple
// Ref : https://www.youtube.com/watch?v=3MmWkR04n_8&t=529s

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

bool find(TreeNode* root, int x)
{
    if(root == NULL)
        return false;
        
    if(root -> val == x)
        return true;
    
    return (find(root -> left, x) || find(root -> right, x));
}

int lcaUtil(TreeNode* root, int b, int c)
{
    if(root == NULL)
        return -1;
    
    if(root -> val == b || root -> val == c)
        return root -> val;
    
    int left = lcaUtil(root -> left, b, c);
    int right = lcaUtil(root -> right, b, c);
    
    if(left != -1 && right != -1)
        return root -> val;
    
    if(left != -1)
        return left;
    
    return right;
}

int Solution::lca(TreeNode* root, int B, int C) 
{
    if(find(root, B) == false || find(root, C) == false || root == NULL)
        return -1;
        
    return lcaUtil(root, B, C);
}

// App 2:
// Simple approach
// Find path of node1 and node2 
// trverse path1 and path2 till they have same value on same index
// last common value will be our answer

int f1 = 0, f2 = 0;

void first_path(int x, vector<int> &path1, TreeNode* root)
{
    if(root == NULL)
        return;
        
    if(root -> val == x)
    {
        f1 = 1;
        path1.push_back(root -> val);
        return;
    }
    
    first_path(x, path1, root -> left);
    if(f1 == 1)
    {
        path1.push_back(root -> val);
        return;
    }
    
    first_path(x, path1, root -> right);
    if(f1 == 1)
    {
        path1.push_back(root -> val);
        return;
    }
}

void second_path(int x, vector<int> &path2, TreeNode* root)
{
    if(root == NULL)
        return;
        
    if(root -> val == x)
    {
        f2 = 1;
        path2.push_back(root -> val);
        return;
    }
    
    second_path(x, path2, root -> left);
    if(f2 == 1)
    {
        path2.push_back(root -> val);
        return;
    }
    
    second_path(x, path2, root -> right);
    if(f2 == 1)
    {
        path2.push_back(root -> val);
        return;
    }
}

int Solution::lca(TreeNode* root, int B, int C) 
{
    f1 = 0;
    f2 = 0;
    
    int ans = 0, i = 0;
    
    vector<int> path1, path2;
    first_path(B, path1, root);
    second_path(C, path2, root);
    
    if(f1 == 0 || f2 == 0)
        return -1;
    
    reverse(path1.begin(), path1.end());
    reverse(path2.begin(), path2.end());
    
    while(i < path1.size() && i < path2.size())
    {
        if(path1[i] == path2[i])
            ans = path1[i++];
        
        else
            break;
    }
    return ans;
}
