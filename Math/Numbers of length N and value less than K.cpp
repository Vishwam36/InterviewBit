// By Vishwam Shriram Mundada
// Question : https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/
// Explanation : https://www.youtube.com/watch?v=MT8zeLak_bI&t=927s
// Good question

int Solution::solve(vector<int> &A, int B, int C) 
{
    if(A.size() == 0)
    {
        return 0;
    }
    
    int ans = 0, number_of_digits = 0, temp = C;
    
    // count number of digits in C
    while(temp)
    {
        temp /= 10;
        number_of_digits++;
    }
    
    /*
    ex.  A = {1, 2, 3, 4}
         B = 3
         C = 23
         in this case there is no posiibility of ans 
         because there is no such 3 digit number < 23
    */
    if(B > number_of_digits)
    {
        return 0;
    }
    
    /*
    ex. A = {0, 1, 2, 3}
        B = 1
        C = 23
        in this case every one digit number is less than 23
        so we will count all possible C digit numbers
    */
    if(B < number_of_digits)
    {
        // if 0 is in set then we will have to exclude those numbers starting from 0
        if(A[0] == 0)
        {
            ans = (A.size() - 1) * pow(A.size(), B - 1);
        }
        else
        {
            ans = pow(A.size(), B);
        }
        
        /* special case in which we have to count 0 also
           ex. A = {0}
               B = 1
               C > 0
        */
        if(B == 1 && A[0] == 0)
        {
            ans++;
        }
        return ans;
    }
    
    // from here starts the solution for the complex case when B == number_of_digits in C
    //                                                   +-----------+
    // store C as array of digits Ex. C = 231, array_c = | 2 | 3 | 1 |
    //                                                   +-----------+
    int array_c[number_of_digits];
    temp = C;
    for(int i = B - 1; i >= 0; --i)
    {
        array_c[i] = temp % 10;
        temp /= 10;
    }
    
    // speacial case when B = 1
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
    
    // just take pen and paper and try writing
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
    
    // we are subtracting one for a number if number formed = C
    if(j == B && flag == 1)
    {
        ans--;
    }
    return ans;
}
