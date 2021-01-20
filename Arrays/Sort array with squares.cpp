// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/sort-array-with-squares/
// easy one
// Complexity : O(n)

vector<int> Solution::solve(vector<int> &A) 
{
    int n = A.size();
    
    vector<int> ans;
    int i = 0;
    while(A[i] < 0)
    {
        i++;
    }
    int j = i;
    --i;
    while(i >= 0 && j < n)
    {
        if(A[i]*A[i] < A[j]*A[j])
        {
            ans.push_back(A[i] * A[i]);
            --i;
        }
        else
        {
            ans.push_back(A[j] * A[j]);
            ++j;
        }
    }
    
    while(i >= 0)
    {
        ans.push_back(A[i] * A[i]);
        --i;
    }
    
    while(j < n)
    {
        ans.push_back(A[j] * A[j]);
        ++j;
    }
    
    return ans;
}

// complexity : O(n*log(n))

vector<int> Solution::solve(vector<int> &A) 
{
    int n = A.size();
    for(int i = 0; i < n; ++i)
    {
        if(A[i] < 0)
        {
            A[i] = A[i] * (-1);
        }
    }
    
    sort(A.begin(), A.end());
    
    for(int i = 0; i < n; ++i)
    {
        A[i] = A[i] * A[i];
    }
    
    return A;
}
