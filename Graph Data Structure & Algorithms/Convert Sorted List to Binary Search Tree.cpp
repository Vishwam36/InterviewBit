// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/
// Decent Tree question

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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* midEle(ListNode* A)
{
    if(A == NULL || A -> next == NULL)
        return A;
    
    ListNode* slow = A;
    ListNode* fast = A;
    ListNode* pre = A;
    while(fast && fast->next)
    {
        pre = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return pre;
}

TreeNode* Solution::sortedListToBST(ListNode* A)
{
    if(A == NULL)
        return NULL;
    
    if(A -> next == NULL)
        return new TreeNode(A -> val);
    
    ListNode* pre = midEle(A);
    ListNode* mid = pre->next;
    
    if(mid == NULL)
        return NULL;

    TreeNode* root = new TreeNode(mid -> val);

    if(mid -> next != NULL)
        root->right = sortedListToBST(mid -> next);
    
    if(A != mid)
    {
        pre->next = NULL;
        root->left = sortedListToBST(A);
    }

    return root;
}
