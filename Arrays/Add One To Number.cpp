// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/add-one-to-number/
// Simple

vector<int> Solution::plusOne(vector<int> &A) 
{
    int n = A.size(), carry = 1;
    int i = n-1;
    vector<int> v(n+1,0);
    
    while(i >= 0)
    {
        v[i+1] = A[i] + carry;
        carry = v[i+1]/10;
        v[i+1] %= 10;
        --i;
    }
    
    if(carry > 0)
        v[i+1] = carry;
    
    while(v[0] == 0)
        v.erase(v.begin());
    
    return v;
}
