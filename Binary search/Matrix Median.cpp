// By vishwam Shriram Mundada
// https://www.interviewbit.com/problems/matrix-median/
// good variety

int Solution::findMedian(vector<vector<int> > &A) 
{
    int max = INT_MIN, min = INT_MAX, r = A.size(), c = A[0].size();
    for(int i = 0; i < r; ++i)
    {
        if(A[i][0] < min)
        {
            min = A[i][0];
        }
        if(A[i][c-1] > max)
        {
            max = A[i][c-1];
        }
    }
    
    // applying binary search on range min to max
    
    int req = ((r * c) / 2) + 1, mid = 0, count = 0;
    while(min < max)
    {
        mid = (min + max) / 2;
        count = 0;
        for(int i = 0; i < r; ++i)
        {
            count += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        }
        if(count < req)
        {
            min = mid+1;
        }
        else
        {
            max = mid;
        }
    }
    return min;
}
