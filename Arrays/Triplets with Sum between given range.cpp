// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/
/*
we will remove waste element among choden triplet
*/

int Solution::solve(vector<string> &A) 
{
    int n = A.size(), i = 0;
    float a, b, c;
    vector<float> v(n);
    for(i = 0; i < n; ++i)
    {
        v[i] = stof(A[i]);
    }
    a = v[0];
    b = v[1];
    c = v[2];
    for(i = 3; i < n; ++i)
    {
        if(a+b+c < 2 && a+b+c > 1)
            return 1;
            
        else if(a+b+c > 2)
        {
            if(a >= b && a >= c)
                a = v[i];
                
            else if(b >= c && b >= a)
                b = v[i];
                
            else
                c = v[i];
        }
        
        else
        {
            if(a <= b && a <= c)
                a = v[i];
                
            else if(b <= c && b <= a)
                b = v[i];
                
            else
                c = v[i];
        }
    }
    if(a+b+c < 2 && a+b+c > 1)
        return 1;
        
    return 0;
}
