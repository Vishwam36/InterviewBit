// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/reorder-list/
// Good question

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) 
{
    if(A == NULL || A -> next == NULL)
        return A;
    
    //find middle: O(n)
    /** even n
     *  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
     *  then slow = 3
     *  
     *  odd n
     *  1 -> 2 -> 3 -> 4 -> 5 -> NULL
     *  then slow = 3
     * */
    ListNode* slow = A,* fast = A;
    while(fast -> next != NULL && fast -> next -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    // cut from the middle and reverse the second half: O(n)
    ListNode* pre = NULL,* post,* curr = slow -> next;
    slow -> next = NULL;
    while(curr != NULL)
    {
        post = curr -> next;
        curr -> next = pre;
        pre = curr;
        curr = post;
    }
    
    // pre will be the head of second half
    // merge two lists: O(n)
    ListNode *p1 = A, *p2 = pre,* temp;
    while(p1 != NULL && p1 -> next != NULL)
    {
        temp = p1 -> next;
        p1 -> next = p2;
        p1 = temp;
        temp = p2 -> next;
        p2 -> next = p1;
        p2 = temp;
    }
    p1 -> next = p2;
    return A;
}
