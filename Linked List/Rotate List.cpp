// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/rotate-list/
// Simple
/*
Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given 1->2->3->4->5->NULL and k = 2
return 4->5->1->2->3->NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) 
{
    if(B == 0 || A == NULL || A -> next == NULL)
        return A;
    
    ListNode* temp = A, *newHead;
    int n = 0;
    
    while(temp != NULL)
    {
        ++n;
        temp = temp -> next;
    }
    
    B %= n;
    
    if(B == n || B == 0)
        return A;
    
    temp = A;
    
    for(int i = 0; i < n-B-1; ++i)
        temp = temp -> next;
    
    newHead = temp -> next;
    temp -> next = NULL;
    temp = newHead;
    
    while(temp -> next != NULL)
        temp = temp -> next;
    
    temp -> next = A;
    return newHead;
}
