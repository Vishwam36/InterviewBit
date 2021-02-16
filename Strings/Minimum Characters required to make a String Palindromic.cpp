// By vishwam Shriram Mundada
// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
// Nice problem, new concept
// refer KMP algo

int Solution::solve(string A) 
{
    string revA = A;
    reverse(revA.begin(), revA.end());
    string concated = A + "$" + revA;
    int l = concated.size();
    
    int i = 0, j = 1, cnt = 0;
    int a[l];
    
    while(j < l)
    {
        if(concated[i] == concated[j])
        {
            cnt++;
            a[j] = cnt;
            ++i;
            ++j;
            if(cnt >= A.size())
                return 0;
        }
        else if(i != 0)
        {
            cnt = 0;
            a[j] = 0;
            i = 0;
        }
        else
        {
            i = 0;
            cnt = 0;
            a[j] = 0;
            j++;
        }
    }
    return A.size() - a[l-1];
}
