// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/woodcutting-made-easy/

long long totalWood(vector<int> A, int h)
{
    long long wood = 0, n = A.size();
    for(int i = 0; i < n; ++i)
    {
        if(A[i] > h)
        {
            wood += (A[i] - h);
        }
    }
    return wood;
}

int Solution::solve(vector<int> &A, int B) 
{
    long long n = A.size(), max = 0, temp = 0;
    for(int i = 0; i < n; ++i)
    {
        if(A[i] > max)
        {
            max = A[i];
        }
    }
    
    long long mid = 0, hi = max, lo = 0;
    
    while(hi - lo > 1)
    {
        mid = (lo + hi) / 2;
        temp = totalWood(A, mid);
        
        if(temp == B)
        {
            return mid;
        }
        else if(temp > B)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    if(totalWood(A, hi) >= B)
    {
        return hi;
    }
    return lo;
}
