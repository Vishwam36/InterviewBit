// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/power-of-two-integers/
// Decent

/*
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example
Input : 4
Output : True  
as 2^2 = 4. 
*/

// App 1:

// IDEA : 
// ex. 1024000000 = (2^16 * 5^6) = (2^8 * 5^3)^2
// but we can only rewrite it as this if we have some common factor in the powers

int Solution::isPower(int n)
{
    if(n == 1)
        return 1;
    
    // m[factor] -> power
    unordered_map<int, int> m;
    int f = 2;
    while(n != 1)
    {
        while(n % f == 0)
        {
            n /= f;
            m[f]++;
        }
        f++;
    }
    
    vector<int> v; // will have all factors' count
    for(auto it : m)
        v.push_back(it.second);
    
    for(int i = 0; i < v.size(); ++i)
        for(int j = 0; j < v.size(); ++j)
            if(__gcd(v[i], v[j]) == 1)
                return 0;
    
    return 1;
}


// App 2: Simple approach

int Solution::isPower(int n) 
{
    if(n == 1)
        return 1;
    
    for(int i = 2; i <= sqrt(n); ++i)
        for(int j = 2; j <= 32; ++j)
            if(pow(i, j) == n)
                return 1;
    
    return 0;
}
