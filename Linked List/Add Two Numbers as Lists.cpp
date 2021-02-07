// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/add-two-numbers-as-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) 
{
    int sum = 0, carry = 0;
    struct ListNode* temp = new ListNode(0);
    struct ListNode* ans = temp;

    // add till the same length (same number of digits)
    while(A != NULL && B != NULL)
    {
        sum = A -> val + B -> val + carry;
        struct ListNode* newNode = new ListNode(sum % 10);
        temp -> next = newNode;
        temp = temp -> next;
        carry = sum / 10;
        A = A -> next;
        B = B -> next;
    }
    
    // if A has more digits
    while(A != NULL)
    {
        sum = A -> val + carry;
        struct ListNode* newNode = new ListNode(sum % 10);
        temp -> next = newNode;
        temp = temp -> next;
        carry = sum / 10;
        A = A -> next;
    }
    
    // else if B has more digits
    while(B != NULL)
    {
        sum = B -> val + carry;
        struct ListNode* newNode = new ListNode(sum % 10);
        temp -> next = newNode;
        temp = temp -> next;
        carry = sum / 10;
        B = B -> next;
    }
    
    // take care of remaining carry
    while(carry)
    {
        sum = carry;
        struct ListNode* newNode = new ListNode(sum % 10);
        temp -> next = newNode;
        temp = temp -> next;
        carry = sum / 10;
    }
    return ans -> next;
}
