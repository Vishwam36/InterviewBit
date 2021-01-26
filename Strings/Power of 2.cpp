// By vishwam Shriram Mundada
// https://www.interviewbit.com/problems/power-of-2/
// good question 
// used method of multiplication of integers out of long long range

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

string toString(int arr[], int size)
{
    string s;
    for(int i = size-1; i >= 0; --i)
    {
        s += ('0' + arr[i]);
    }
    return s;
}

int Solution::power(string A) 
{
    int res[100000];
    int size = 1;
    res[0] = 1;
    
    while(A.size() >= size)
    {
        size = multiply(2, res, size);
        if(A == toString(res, size))
        {
            return 1;
        }
    }
    return 0;
}
