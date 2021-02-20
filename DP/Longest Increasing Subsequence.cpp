// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/longest-increasing-subsequence/
// decent, standard question

int Solution::lis(const vector<int> &A) 
{
    int n = A.size();
    
    vector<int> v;
    v.push_back(A[0]);
    
    for(int i = 1; i < n; ++i)
    {
        if(A[i] > v.back())
        {
            v.push_back(A[i]);
        }
        else
        {
            int index = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
            v[index] = A[i];
        }
    }
    return v.size();
}
