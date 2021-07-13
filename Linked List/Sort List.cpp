// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/sort-list/
// Decent

/*
Sort a linked list in O(n log n) time using constant space complexity.

Example :
Input : 1 -> 5 -> 4 -> 3
Returned list : 1 -> 3 -> 4 -> 5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int length(ListNode* head)
{
    int n = 0;
    while(head)
    {
        head = head->next;
        ++n;
    }
    return n;
}

ListNode* merge(ListNode* t1, ListNode* t2)
{
    ListNode* newHead = new ListNode(-1);
    ListNode* temp = newHead;
    
    while(t1 && t2)
    {
        if(t1->val <= t2->val)
        {
            temp->next = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            t2 = t2->next;
        }
        temp = temp->next;
    }
    
    if(t1)
        temp->next = t1;
    else
        temp->next = t2;
    
    return newHead->next;
}

ListNode* Solution::sortList(ListNode* head)
{
    if(head->next == NULL)
        return head;
    
    ListNode* head2 = head, *pre;
    
    int n = length(head);
    for(int i = 0; i < n/2; ++i)
    {
        pre = head2;
        head2 = head2->next;
    }
    
    pre->next = NULL;
    
    head = sortList(head);
    head2 = sortList(head2);
    
    return merge(head, head2);
}
