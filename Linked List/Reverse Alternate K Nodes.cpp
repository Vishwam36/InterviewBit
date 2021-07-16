// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/reverse-alternate-k-nodes/
// Decent

/*
Problem Description
Given a linked list A of length N and an integer B.
You need to reverse every alternate B nodes in the linked list A.

Problem Constraints
    1 <= N <= 10^5
    1<= Value in Each Link List Node <= 10^3
    1 <= B <= N
    N is divisible by B

Input Format
First argument is the head pointer of the linkedlist A.
Second argument is an integer B.

Output Format
Return the head pointer of the final linkedlist as described.

Example Input
Input 1:
 A = 3 -> 4 -> 7 -> 5 -> 6 -> 6 -> 15 -> 61 -> 16
 B = 3

Input 2:
 A = 1 -> 4 -> 6 -> 6 -> 4 -> 10
 B = 2

Example Output
Output 1:
 7 -> 4 -> 3 -> 5 -> 6 -> 6 -> 16 -> 61 -> 15

Output 2:
 4 -> 1 -> 6 -> 6 -> 10 -> 4

Example Explanation
Explanation 1:
 The linked list contains 9 nodes and we need to reverse alternate 3 nodes.
 First sublist of length 3  is 3 -> 4 -> 7 so on reversing it we get 7 -> 4 -> 3.
 Second sublist of length 3 is 5 -> 6 -> 6 we don't need to reverse it.
 Third sublist of length 3 is 15 -> 61 -> 16 so on reversing it we get 16 -> 61 -> 15.

Explanation 2:
 The linked list contains 6 nodes and we need to reverse alternate 2 nodes.
 First sublist of length 2 is 1 -> 4 so on reversing it we get 4 -> 1.
 Second sublist of length 2 is 6 -> 6 we don't need to reverse it.
 Third sublist of length 2 is 4 -> 10 so on reversing it we get 10 -> 4.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverse(ListNode* head, int B, bool f)
{
    if(!head)
        return NULL;
    
    ListNode* pre = head, *curr = head, *post;
    
    if(!f) // dont reverse
    {
        for(int i = 0; i < B; ++i)
        {
            pre = curr;
            curr = curr->next;
        }
        pre->next = reverse(curr, B, !f);
        return head;
    }
    
    // f=1 . Reverse
    for(int i = 0; i < B && curr; ++i)
    {
        post = curr->next;
        curr->next = pre;
        pre = curr;
        curr = post;
    }
    
    head->next = reverse(curr, B, !f);
    return pre;
}

ListNode* Solution::solve(ListNode* head, int B) 
{
    return reverse(head, B, 1);
}
