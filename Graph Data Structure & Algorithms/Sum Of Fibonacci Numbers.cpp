// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/
// Easy greedy, but I dont understand role of graph here

long long f[50];

void calculate()
{
    f[0] = 1;
    f[1] = 1;
    
    for(int i = 2; i < 50; ++i)
        f[i] = f[i-1] + f[i-2];
}

int find(int A)
{
    for(int i = 1; i < 50; ++i)
        if(f[i] > A)
            return f[i-1];
}

int Solution::fibsum(int A) 
{
    calculate();
    int ans = 0;
    while(A)
    {
        A = A - find(A);
        ++ans;
    }
    return ans;
}
