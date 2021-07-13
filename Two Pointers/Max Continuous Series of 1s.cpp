// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/max-continuous-series-of-1s/
// Decent

/*
You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:
Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.
*/

vector<int> Solution::maxone(vector<int> &a, int m) 
{
    int n = a.size();
    int l = 0, r = 0, idx = 0, maxLen = 0;
    
    while(m && r < n)
    {
        if(a[r] == 0)
            m--;
        
        ++r;
    }
    while(r < n && a[r] == 1)
        ++r;
    
    maxLen = r-l;

    while(r < n)
    {
        if(a[l] == 0)
            ++m;
            
        ++l;
        
        while(m && r < n)
        {
            if(a[r] == 0)
                m--;
            
            ++r;
        }
        while(r < n && a[r] == 1)
            ++r;
        
        if(r-l > maxLen)
        {
            maxLen = r-l;
            idx = l;
        }
    }
    
    vector<int> ans;
    while(maxLen--)
        ans.push_back(idx++);
    return ans;
}
