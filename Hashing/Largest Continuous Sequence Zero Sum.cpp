// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/
// Easy

vector<int> Solution::lszero(vector<int> &A) 
{
    int n = A.size(), max_length = 0, sum = 0, start = -1, end = -1;
    
    vector<int> v;
    
    map<int, int> m;
    // To handle the cases which start from index 0.
    m[0] = -1;
    
    for(int i = 0; i < n; ++i)
    {
        sum += A[i];
        if(m.find(sum) != m.end())
        {
            if(max_length < i - m[sum])
            {
                start = m[sum] + 1;
                max_length = i - m[sum];
                end = i;
            }
        }
        else
        {
            m[sum] = i;
        }
    }
    if(start >= 0 && end <= n-1)
        for(int i = start; i <= end; ++i)
            v.push_back(A[i]);
    
    return v;
}
