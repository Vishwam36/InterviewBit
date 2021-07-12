// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/bst-iterator/
// 

/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.
    Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
    Try to optimize the additional space complexity apart from the amortized time complexity. 
*/

// App 1 : Simple inorder traversal

vector<int> in;
int it;

void rec(TreeNode* root)
{
    if(!root)
        return;
    
    rec(root->left);
    in.push_back(root->val);
    rec(root->right);
}

BSTIterator::BSTIterator(TreeNode *root) {
    in.clear();
    rec(root);
    it = 0;
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return it != in.size();
}

/** @return the next smallest number */
int BSTIterator::next() {
    return in[it++];
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

// App 2 : 
// Morris traversal
// IDK how morris inorder is O(n) traversal ?

// REF : https://www.youtube.com/watch?v=wGXB9OWhPTg

TreeNode* it;

BSTIterator::BSTIterator(TreeNode *root) {
    it = root;
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return it != NULL;
}

/** @return the next smallest number */
int BSTIterator::next() {
    int ans;
    
    while(it)
    {
        if(!it->left)
        {
            ans = it->val;
            it = it->right;
            return ans;
        }
        else
        {
            TreeNode* pre = it->left;
            while(pre->right != NULL && pre->right != it)
                pre = pre->right;
            
            if(pre->right == NULL)
            {
                pre->right = it;
                it = it->left;
            }
            else
            {
                pre->right = NULL;
                ans = it->val;
                it = it->right;
                return ans;
            }
        }
    }
    return ans;
}
