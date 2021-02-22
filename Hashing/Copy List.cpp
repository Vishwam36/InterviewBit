// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/copy-list/
// Good question
// same as clone linked list

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) 
{
    if(A == NULL)
        return A;
    
    RandomListNode* temp = A;

    while(temp != NULL)
    {
        RandomListNode* newNode = new RandomListNode(temp -> label);
        newNode -> next = temp -> next;
        temp -> next = newNode;
        temp = newNode -> next;
    }
    
    temp = A;
    while(temp)
    {
        if(temp -> random)
        {
            temp -> next -> random = temp -> random -> next;
        }
        temp = temp -> next -> next;
    }
    
    RandomListNode* newHead = A -> next;
    RandomListNode* copyTemp = newHead;
    RandomListNode* post = newHead -> next;
    temp = A;
    
    while(temp && copyTemp)
    {
        post = copyTemp -> next;
        temp -> next = post;
        
        if(post)
            copyTemp -> next = post -> next;
        
        temp = temp -> next;
        copyTemp = copyTemp -> next;
    }
    
    return newHead;
}
