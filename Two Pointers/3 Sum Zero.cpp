// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/3-sum-zero/
// Decent
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.
*/

bool equal(vector<int> a, vector<int> b)
{
    return (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]);
}

vector<vector<int> > Solution::threeSum(vector<int> &A) 
{
    int n = A.size();
    sort(A.begin(), A.end());
    vector<vector<int> > v;

    int l = 0, r = 0;
    for(int i = 0; i < n-2; ++i)
    {
        if(i > 0 && A[i] == A[i-1])
            continue;
        
        l = i+1, r = n-1;
        
        while(l < r)
        {
            long long sum = (long long)A[i] + (long long)A[l] + (long long)A[r];
            if(sum == 0)
            {
                vector<int> temp = {A[i], A[l], A[r]};
                if(v.size() == 0)
                    v.push_back(temp);
                
                if(!equal(temp, v.back()))
                    v.push_back(temp);
                
                ++l;
                --r;
            }
            else if(sum < 0)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return v;
}
