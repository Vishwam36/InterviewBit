// by Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/min-xor-value/

/*
The theorem used here is,
if A <= C <= B
then either A ^ C or C ^ B is smaller than A ^ B
*/

int Solution::findMinXor(vector<int> &A) 
{
    sort(A.begin(), A.end());
    int ans = 1000000000;
    
    for(int i = 0; i < A.size() - 1; ++i)
        ans = min(A[i] ^ A[i + 1], ans);
        
    return ans;
}
