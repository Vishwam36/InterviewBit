// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/even-reverse/
// Given a linked list A , reverse the order of all nodes at even positions.
// take pen and paper

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverse(ListNode* A)
{
    struct ListNode* curr = A;
    struct ListNode* pre = NULL;
    struct ListNode* post = A -> next;
    while(curr != NULL)
    {
        post = curr -> next;
        curr -> next = pre;
        pre = curr;
        curr = post;
    }
    return pre;
}
 
ListNode* Solution::solve(ListNode* A) 
{
    int i = 1;
    struct ListNode* temp = A;
    struct ListNode* tempEven = new ListNode(0);
    struct ListNode* tempOdd = new ListNode(0);
    struct ListNode* odd = new ListNode(-1);
    struct ListNode* even = new ListNode(-1);
    tempEven = even;
    tempOdd = odd;
    while(temp != NULL)
    {
        if(i % 2 == 0)
        {
            tempEven -> next = temp;
            tempEven = tempEven -> next;
        }
        else
        {
            tempOdd -> next = temp;
            tempOdd = tempOdd -> next;
        }
        ++i;
        temp = temp -> next;
    }
    tempOdd -> next = NULL;
    tempEven -> next = NULL;

    even = reverse(even -> next);
    tempEven = even;
    
    odd = odd -> next;
    tempOdd = odd;
    
    i = 1;
    temp  = new ListNode(-1);
    
    while(temp != NULL)
    {
        if(i % 2 == 0)
        {
            temp -> next = tempEven;
            if(tempEven == NULL)
            {
                break;
            }
            tempEven = tempEven -> next;
        }
        else
        {
            temp -> next = tempOdd;
            if(tempOdd == NULL)
            {
                break;
            }
            tempOdd = tempOdd -> next;
        }
        temp = temp -> next;
        ++i;
    }
    return odd;
}
