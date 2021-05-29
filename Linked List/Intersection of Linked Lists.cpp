// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/intersection-of-linked-lists/
// Decent

/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

    Notes:
        If the two linked lists have no intersection at all, return null.
        The linked lists must retain their original structure after the function returns.
        You may assume there are no cycles anywhere in the entire linked structure.
        Your code should preferably run in O(n) time and use only O(1) memory.
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
        n++;
    }
    return n;
}

ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B)
{
    int na = length(A);
    int nb = length(B);
    
    if(na < nb)
    {
        ListNode* temp = A;
        A = B;
        B = temp;
    }
    
    int d = abs(na-nb); // extra nodes in longer LL
    while(d)
    {
        A = A->next;
        --d;
    }
    //both A and B are now equidistant from merge point
    while(A && B)
    {
        if(A == B)
            return A;
        
        A = A->next;
        B = B->next;
    }
    return NULL;
}
