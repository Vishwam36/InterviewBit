// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/fraction/
// Good question

typedef long long ll;

string Solution::fractionToDecimal(int a, int b)
{
    string ans, strAfterPoint;
    ll A = a, B = b;
    if((A < 0 && B > 0) || (A > 0 && B < 0))
        ans = "-";
    
    A = abs(A);
    B = abs(B);
    
    if(A % B == 0)
        return to_string(A/B);
    
    ll remain = A % B, dividend = 0;
    map<int, int> m;
    
    while(remain != 0 && m.find(remain) == m.end())
    {
        m[remain] = strAfterPoint.size();
        dividend = (remain * 10) / B;
        remain = (remain * 10) % B;
        strAfterPoint += to_string(dividend);
    }
    
    if(remain != 0)
        strAfterPoint = strAfterPoint.substr(0, m[remain]) 
                        + "(" 
                        + strAfterPoint.substr(m[remain]) 
                        + ")";
    
    ans += to_string(A/B) + "." + strAfterPoint;
    
    return ans;
}
