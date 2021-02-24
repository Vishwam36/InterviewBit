// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/
// easy 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) 
{
    if(!A || !A -> next)
        return A;
        
    ListNode* temp = A;
    ListNode* post = A;
    ListNode* newHead = A -> next;
    ListNode* pre = new ListNode(-1);
    
    // always put temp before temp -> next in such conditions
    // because if temp = NULL and if we calculate temp -> next it will give Run Time Error
    while(temp && temp -> next)
    {
        post = temp -> next -> next;
        temp -> next -> next = temp;
        pre -> next = temp -> next;
        pre = temp;
        temp -> next = post;
        temp = post;
    }
    return newHead;
}
