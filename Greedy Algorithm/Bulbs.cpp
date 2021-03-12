// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/interview-questions/
// Easy

int Solution::bulbs(vector<int> &A) 
{
    int n = A.size(), find = 0, press = 0;
    
    for(int i = 0; i < n; ++i)
    {
        if(A[i] == find)
        {
            ++press;
            
            if(find == 0)
                find = 1;
            else
                find = 0;
        }
    }
    return press;
}
