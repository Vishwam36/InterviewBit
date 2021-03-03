// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/merge-k-sorted-lists/
// Simple 
// 'Merge K sorted arrays!' is bit more difficult than this

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct cmp
{
    bool operator()(ListNode* a, ListNode* b)
    {
        return a -> val > b -> val;
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A)
{
    ListNode* ans = new ListNode(-1);
    ListNode* temp = ans;

    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
    
    for(int i = 0; i < A.size(); ++i)
        pq.push(A[i]);
    
    while(!pq.empty())
    {
        temp -> next = pq.top();
        temp = temp -> next;
        
        pq.pop();
        
        if(temp -> next != NULL)
            pq.push(temp -> next);
    }
    
    return ans -> next;
}
