// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/reverse-link-list-ii/
// Decent one if done in one pass (looping only once)
// Ref : https://www.youtube.com/watch?v=GSJuwQzKSnI&ab_channel=NickWhite
/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.
*/

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) 
{
    if(B >= C || A == NULL)
        return A;
    
    ListNode* start = A;
    ListNode* end = A;
    ListNode* curr = A;
    ListNode* pre = NULL;
    ListNode* post = A -> next;
    
    while(B > 1)
    {
        B--;
        C--;
        post = curr -> next;
        pre = curr;
        curr = curr -> next;
    }
    
    start = pre;
    end = curr;
    
    while(C > 0)
    {
        C--;
        post = curr -> next;
        curr -> next = pre;
        pre = curr;
        curr = post;
    }
    
    if(start != NULL)
    {
        start -> next = pre;
    }
    else
    {
        A = pre;
    }
    end -> next = curr;
    
    return A;
}
