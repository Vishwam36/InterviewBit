// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/
// Good question


int Solution::solve(vector<int> &A, int B, int C) 
{
    if(A.size() == 0)
    {
        return 0;
    }
    
    int ans = 0, number_of_digits = 0, temp = C;
    while(temp)
    {
        temp /= 10;
        number_of_digits++;
    }
    
    if(B > number_of_digits)
    {
        return 0;
    }
    
    if(B < number_of_digits)
    {
        if(A[0] == 0)
        {
            ans = (A.size() - 1) * pow(A.size(), B - 1);
        }
        else
        {
            ans = pow(A.size(), B);
        }
        if(B == 1 && A[0] == 0)
        {
            ans++;
        }
        return ans;
    }
    
    int array_c[number_of_digits];
    temp = C;
    for(int i = B - 1; i >= 0; --i)
    {
        array_c[i] = temp % 10;
        temp /= 10;
    }
    
    if(B == 1)
    {
        for(int i = 0; i < A.size(); ++i)
        {
            if(A[i] < C)
            {
                ans++;
            }
        }
        return ans;
    }
    
    int j = 1;
    int flag = 0;
    int newCount = 0;
    for(int i = 0; i < A.size(); ++i)
    {
        if(A[i] == 0)
        {
            continue;
        }
        if(A[i] > array_c[0])
        {
            break;
        }
        newCount++;
    }
    ans += newCount * pow(A.size(), B - 1);
    
    for(int i = 0; i < A.size(); ++i)
    {
        if(A[i] == array_c[0])
        {
            flag = 1;
        }
    }
    
    while(flag == 1 && j < B)
    {
        flag = 0;
        newCount = 0;
        for(int i = 0; i < A.size(); ++i)
        {
            if(A[i] > array_c[j])
            {
                newCount++;
            }
            if(A[i] == array_c[j])
            {
                flag = 1;
            }
        }
        ans -= newCount * (pow(A.size(), B-j-1));
        ++j;
    }
    if(j == B && flag == 1)
    {
        ans--;
    }
    return ans;
}
