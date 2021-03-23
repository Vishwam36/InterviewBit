// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/insertion-sort-list/
// Decent

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::insertionSortList(ListNode* A) 
{
    ListNode* i = A;
    ListNode* head = A;
    ListNode* start = new ListNode(0);
    start -> next = head;
    ListNode* pre = start;
    
    while(i != NULL)
    {
        if(i -> next && i->val > i->next->val)
        {
            while(pre->next && pre->next->val < i->next->val)
            {
                pre = pre -> next;
            }
            ListNode* temp = pre -> next;
            pre -> next = i -> next;
            i -> next = i -> next -> next;
            pre -> next -> next = temp;
            pre = start;
        }
        else
        {
            i = i -> next;
        }
    }
    return start -> next;
}
