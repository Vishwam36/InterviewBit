// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/large-factorial/

int multiply(int x, int res[], int size)
{
    int carry = 0;
    for(int i = 0; i < size; ++i)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod/10;
    }
    
    while(carry > 0)
    {
        res[size] = carry % 10;
        carry = carry / 10;
        size++;
    }
    
    return size;
}

string factorial(int n)
{
    string ans;
    int res[500];
    res[0] = 1;
    int size = 1;
    for(int i = 2; i <= n; ++i)
    {
        size = multiply(i, res, size);
    }
    for(int i = size - 1; i >= 0; --i)
    {
        ans += (res[i] + '0');
    }
    return ans;
}

string Solution::solve(int A) 
{
    return factorial(A);
}
