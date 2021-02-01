// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/numrange/

int Solution::numRange(vector<int> &A, int B, int C) 
{
    long long ans = 0, sum = 0, n = A.size();
    long long preSum[n + 1];
    preSum[0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        sum += A[i - 1];
        preSum[i] = sum;
    }
    sum = 0;
    
    for(int i = 0; i <= n; ++i)
    {
        for(int j = i+1; j <= n; ++j)
        {
            if(((preSum[j] - preSum[i]) >= B) && ((preSum[j] - preSum[i]) <= C))
            {
                ++ans;
            }
            if((preSum[j] - preSum[i]) > C)
            {
                break;
            }
        }
    }
    
    return ans;
}
