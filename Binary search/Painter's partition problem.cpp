// By Vishwam Mundada
// Written function only which was asked

bool can(int A, int B, vector<int> &C, int mid)
{
    long long n=C.size(), curr=C[0], sum=0;
    for(long long i=0;i<n;++i)
    {
        sum+=C[i];
        if(sum>mid)
        {
            --i;
            --A;
            curr=C[i];
            sum=0;
        }
        if(A==0)
        {
            return false;
        }
    }
    return true;
}
