// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/excel-column-title/

string Solution::convertToTitle(int A) 
{
    int flag = 0, temp = 0;
    string ans;
    while(A)
    {
        temp = A % 26;
        if(temp == 0)
        {
            temp = 26;
        }
        ans += ('A' + temp - 1);
        A /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
