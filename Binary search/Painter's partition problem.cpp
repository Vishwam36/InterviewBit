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

long long binary(int A, int B, vector<int> &C, int max, int sum)
{
    long long l=0,r=sum,mid=0;
    while(r-l>1)
    {
        mid=(l+r)/2;
        bool temp = can(A,B,C,mid);
        if(temp)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    if(can(A,B,C,l))
    {
        return l%10000003;
    }
    return r%10000003;
}

int Solution::paint(int A, int B, vector<int> &C) {
    long long n=C.size(),max=0,sum=0;
    for(long long i=0;i<n;++i)
    {
        C[i]%=10000003;
        sum+=C[i];
        sum=sum%10000003;
        if(C[i]>max)
        {
            max=C[i];
        }
    }
    if(A>C.size())
    {
        return max*(B%10000003);
    }
    long long ans = binary(A,B,C,max,sum)*(B%10000003);
    ans = ans%10000003;
    return (int)ans;
}
