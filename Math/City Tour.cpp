// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/city-tour/
// Good question
// permutation & combination, modulo of division

long long m = 1000000007;
long long fact[1001];

void calculateFactorial()
{
    fact[0] = 1;
    for(int i = 1; i <= 1000; ++i)
    {
        fact[i] = i * fact[i-1];
        fact[i] = fact[i] % m;
    }
}

long long myPow(long long a, long long b)
{
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    
    long long ans = 1;
    if(b % 2 == 0)
    {
        ans = myPow(a, b/2);
        ans %= m;
        ans = ans * ans;
        ans %= m;
    }
    else
    {
        ans = myPow(a, b/2);
        ans %= m;
        ans = ans * ans;
        ans %= m;
        ans = ans * a;
        ans %= m;
    }
    return ans;
}

int Solution::solve(int A, vector<int> &B) 
{
    calculateFactorial();
    sort(B.begin(), B.end());
    long long ans = 1;
    
    int n = A - B.size();
    
    vector<int> v;
    v.push_back(B[0] - 1);
    for(int i = 1; i < B.size(); ++i)
    {
        v.push_back(B[i] - B[i-1] - 1);
    }
    v.push_back(A - B.back());
    
    ans = fact[n];
    for(int i = 0; i < v.size(); ++i)
    {
        ans *= (((long long)myPow(fact[v[i]], m-2)) % m);
        ans = ans % m;
    }
    for(int i = 1; i < v.size()-1; ++i)
    {
        if(v[i] < 2)
            continue;
        
        ans *= myPow(2, v[i] - 1);
        ans %= m;
    }
    return ans;
}
