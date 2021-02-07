// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/k-reverse-linked-list/
// Tricky

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) 
{
    struct ListNode* curr,* pre,* post;
    curr = A;
    pre = NULL;
    post = A -> next;
    int cnt = B;
    while(curr != NULL && cnt > 0)
    {
        cnt--;
        post = curr -> next;
        curr -> next = pre;
        pre = curr;
        curr = post;
    }
    if(post != NULL)
    {
        A -> next = reverseList(post, B);
    }
    return pre;
}
