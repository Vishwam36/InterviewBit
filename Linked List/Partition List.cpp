// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/partition-list/
// simple

ListNode* Solution::partition(ListNode* A, int B) 
{
    struct ListNode* smaller = new ListNode(-1);
    struct ListNode* greater = new ListNode(-1);
    struct ListNode* smallerStart = smaller;
    struct ListNode* greaterStart = greater;
    struct ListNode* temp = A;
    
    while(temp != NULL)
    {
        if(temp -> val < B)
        {
            smaller -> next = temp;
            smaller = smaller -> next;
        }
        else
        {
            greater -> next = temp;
            greater =  greater -> next;
        }
        temp = temp -> next;
    }
    
    greater -> next = NULL;
    smaller -> next = NULL;
    
    if(smallerStart -> next != NULL)
        smaller -> next = greaterStart -> next;
    else
        smallerStart = greaterStart;
    
    return smallerStart -> next;
}
