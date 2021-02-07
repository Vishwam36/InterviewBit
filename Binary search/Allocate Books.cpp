// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/allocate-books/
// Good problem

bool can(int x, vector<int> A, int B, int n)
{
    int last_book = 0, sum=0;
    for(int i=0;i<n;++i)
    {
        if(B==0)
            return false;
            
        sum+=A[i];
        if(sum>x)
        {
            B--;
            sum=0;
            --i;
        }
    }
    if(B>=0)
        return true;
    return false;
}

int Solution::books(vector<int> &A, int B) 
{
    int last_book=0, n=A.size(), sum=0, maxx=INT_MIN;
    if(B>n)
        return -1;
    for(int i=0;i<n;++i)
    {
        sum += A[i];
        
        if(maxx < A[i])
            maxx = A[i];
    }
    
    int l=maxx, r=sum, mid=0;
    while(r-l > 1)
    {
        mid = (l+r)/2;
        bool temp = can(mid,A,B,n);
        
        if(temp == true)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    if(can(l,A,B,n))
        return l;
    return r;
}
