// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/highest-product/
// Very easy

int Solution::maxp3(vector<int> &A) 
{
    int ans = 0, n = A.size();
    if(n < 3)
        return ans;
    
    sort(A.begin(), A.end());
    ans = max(A[0]*A[1]*A[n-1], A[n-1]*A[n-2]*A[n-3]);
    return ans;
}
