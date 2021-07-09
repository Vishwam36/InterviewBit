// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/remove-duplicates-from-sorted-list-ii/
// Easy

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::deleteDuplicates(ListNode* head) 
{
    ListNode* newHead = new ListNode(-1);
    newHead->next = head;
    
    ListNode* pre = newHead, *curr = head, *post;
    
    while(curr && curr->next)
    {
        post = curr->next;
        if(post && curr->val == post->val)
        {
            while(post && post->val == curr->val)
                post = post->next;
            
            pre->next = post;
        }
        else
        {
            pre = curr;
        }
        curr = post;
    }
    return newHead->next;
}
