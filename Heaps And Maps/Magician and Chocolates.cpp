// By Vishwam shriram Mundada
// https://www.interviewbit.com/problems/magician-and-chocolates/
// Simple

#define MOD 1000000007

int Solution::nchoc(int A, vector<int> &B) 
{
    long long ans = 0;
    
    priority_queue<int> pq;
    
    for(int i = 0; i < B.size(); ++i)
        pq.push(B[i]);
    
    while(A--)
    {
        ans += pq.top();
        ans %= MOD;
        pq.push(pq.top() / 2);
        pq.pop();
    }
    
    return ans;
}
