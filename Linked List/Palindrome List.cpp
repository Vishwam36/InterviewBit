// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/palindrome-list/
// idea is to reverse second half of the linked list and check for the palindrome

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) 
{
    struct ListNode* temp = A;
    struct ListNode* lastNode = NULL;
    int count = 0;
    while(temp != NULL)
    {
        temp = temp -> next;
        if(temp != NULL)
        {
            lastNode = temp;
        }
        count++;
    }
    temp = A;
    struct ListNode* pre,* curr,* post;
    pre = NULL;
    curr = NULL;
    
    // if number of nodees are even
    if(count % 2 == 0)
    {
        for(int i = 0; i < (count / 2); ++i)
        {
            temp = temp -> next;
        }
        curr = temp;
        while(curr != NULL)
        {
            post = curr -> next;
            curr -> next = pre;
            pre = curr;
            curr = post;
        }
        while(pre != NULL)
        {
            if(A -> val != pre -> val)
            {
                return 0;
            }
            A = A -> next;
            pre = pre -> next;
        }
    }
    
    // when number of nodes are odd
    else
    {
        for(int i = 0; i < (count / 2); ++i)
        {
            temp = temp -> next;
        }
        temp = temp -> next;
        curr = temp;
        while(curr != NULL)
        {
            post = curr -> next;
            curr -> next = pre;
            pre = curr;
            curr = post;
        }
        while(pre != NULL)
        {
            if(A -> val != pre -> val)
            {
                return 0;
            }
            A = A -> next;
            pre = pre -> next;
        }
    }
    return 1;
}
