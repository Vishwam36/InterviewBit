// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/max-product-subarray/
// Easy, tricky

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
Return an integer corresponding to the maximum product possible.

Example :
Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]
*/

int Solution::maxProduct(const vector<int> &A)
{
    long long pro1 = 1, pro2 = 1, max1 = INT_MIN, max2 = INT_MIN;
    
    for(int i = 0; i < A.size(); ++i)
    {
        pro1 *= A[i];
        max1 = max(max1, pro1);
        if(A[i] == 0)
            pro1 = 1;
    }
    for(int i = A.size()-1; i >= 0; --i)
    {
        pro2 *= A[i];
        max2 = max(max2, pro2);
        if(A[i] == 0)
            pro2 = 1;
    }
    
    return max(max1, max2);
}
