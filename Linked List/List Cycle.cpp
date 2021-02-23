// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/list-cycle/
// Simple trick used

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

App 1 : Simple
ListNode* Solution::detectCycle(ListNode* A)
{
    ListNode* post = NULL;
    ListNode* temp = A;
    ListNode* common = new ListNode(-1);
    
    while(temp != NULL)
    {
        if(temp -> next == common)
            return temp;
        
        post = temp -> next;
        temp -> next = common;
        temp = post;
    }
    return NULL;
}

App 2 : Lengthy but new concept
Ref : https://www.codesdope.com/blog/article/detect-and-remove-loop-in-a-linked-list/
Ref : https://www.youtube.com/watch?v=Qo1GXMgIjxk&ab_channel=bhaicodekaro

ListNode* Solution::detectCycle(ListNode* A)
{
    ListNode* fast = A;
    ListNode* slow = A;
    bool loop = false;
    
    while(slow && fast && fast -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast)
        {
            loop = true;
            break;
        }
    }
    
    slow = A;
    if(loop)
    {
        while(slow != fast) // Why the slow and fast will meet is the only difficult thing to understand in this approach
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
    return NULL;
}
