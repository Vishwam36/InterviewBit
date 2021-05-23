// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/majority-element/
// App 1 is tricky, App 2 is easy

// App 1:Boyer–Moore majority vote algorithm
int Solution::majorityElement(const vector<int> &A) 
{
    int n = A.size(), maxIndex = 0, count = 1;
    
    for(int i = 1; i < n; ++i)
    {
        if(A[maxIndex] == A[i])
            count++;
        else
            count--;
        
        if(count == 0)
        {
            maxIndex = i;
            count = 1;
        }
    }
    return A[maxIndex];
}


// App 2: Naive
int Solution::majorityElement(const vector<int> &A) 
{
    unordered_map<int, int> m;
    
    int n = A.size();
    for(int i = 0; i < n; ++i)
    {
        m[A[i]]++;
        if(m[A[i]] > floor(n/2))
            return A[i];
    }
}
