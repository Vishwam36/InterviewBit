// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/next-similar-number/
// Tricky good question

string Solution::solve(string A) 
{
    if(A.size() == 1)
        return "-1";
    
    int flag = 0, n = A.size(), d = n-1;
    
    for(int i = n-1; i >= 1; --i)
        if(A[i] > A[i-1])
        {
            d = i - 1;
            break;
        }
    
    if(d == n-1)
        return "-1";
    
    int min = d+1;
    
    for(int i = d+1; i < n; ++i)
        if(A[i] > A[d] && A[i] < A[min])
            min = i;
    
    swap(A[min], A[d]);
    vector<char> temp;
    
    for(int i = d+1; i < n; ++i)
        temp.push_back(A[i]);
    
    sort(temp.begin(), temp.end());
    A.erase(d+1, n-1);
    
    for(int i = 0; i < temp.size(); ++i)
        A += temp[i];
    
    return A;
}
