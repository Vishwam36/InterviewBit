// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/max-non-negative-subarray/
// This is not optimized code

bool cmp(pair<long long,int> p1, pair<long long,int> p2)
{
    if(p1.first == p2.first)
    {
        return p1.second > p2.second;
    }
    return p1.first > p2.first;
}

vector<int> Solution::maxset(vector<int> &A) 
{
    vector<int> ans;
    vector<pair<long long,int> > v;
    long long n = A.size(), sum = 0, maxElements = 0;

    for(int i = 0; i < n; ++i)
    {
        if(A[i] >= 0)
        {
            maxElements++;
            sum += A[i];
            v.push_back(make_pair(sum, maxElements));
        }
        else
        {
            sum = 0;
            maxElements = 0;
        }
    }
    if(v.size() == 0)
    {
        return ans;
    }
    
    // just calculate maximun sum with maximum number of elements
    sort(v.begin(), v.end(), cmp);
    maxElements = 0;
    sum = 0;
    
    for(int i = 0; i < n; ++i)
    {
        if(A[i] >= 0)
        {
            ans.push_back(A[i]);
            maxElements++;
            sum += A[i];
        }
        else
        {
            maxElements = 0;
            ans.clear();
            sum = 0;
        }
        
        // v[0].first = maximum sum and v[0].second = maximum size of subarray having maximum sum
        if(sum == v[0].first && maxElements == v[0].second)
        {
            return ans;
        }
    }
    return ans;
}
