// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/reverse-linked-list/
// simple but often I forget it

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct ListNode* reverse(ListNode* A)
{
    struct ListNode *pre, *curr, *post;
    curr = A;
    pre = NULL;
    post = A -> next;
    while(curr != NULL)
    {
        post = curr -> next;
        curr -> next = pre;
        pre = curr;
        curr = post;
    }
    return pre;
}
 
ListNode* Solution::reverseList(ListNode* A) 
{
    A = reverse(A);
    return A;
}
