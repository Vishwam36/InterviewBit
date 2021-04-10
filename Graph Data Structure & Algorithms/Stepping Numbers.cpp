// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/stepping-numbers/
// Decent, dont understand why is it graph question

void rec(int a, int b, long long num, vector<int> &ans)
{
    if(num > b)
        return;
    
    if(num >= a)
        ans.push_back(num);
    
    int lastDigit = num % 10;
    
    if(lastDigit == 0)
        rec(a, b, num*10 + 1, ans);
    
    else if(lastDigit == 9)
        rec(a, b, num*10 + 8, ans);
    
    else
    {
        rec(a, b, num*10 + lastDigit-1, ans);
        rec(a, b, num*10 + lastDigit+1, ans);
    }
}

vector<int> Solution::stepnum(int a, int b) 
{
    vector<int> ans;
    
    if(b < a)
        return ans;
    
    if(a == 0)
        ans.push_back(0);
    
    for(int i = 1; i < 10; ++i)
        rec(a, b, (long long)i, ans);
    
    if(ans.size() > 0)
        sort(ans.begin(), ans.end());
    
    return ans;
}
