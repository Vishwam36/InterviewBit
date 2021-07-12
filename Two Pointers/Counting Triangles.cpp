// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/counting-triangles/
// Easy

/*
You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.

Notes:
    You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a 
	positive area.
    Return answer modulo 109 + 7.

For example,
A = [1, 1, 1, 2, 2]
Return: 4
*/

int Solution::nTriang(vector<int> &A)
{
    const long long MOD = 1000000007;
    long long ans = 0;
    sort(A.begin(), A.end());
    
    for(int i = 0; i < A.size()-2; ++i)
    {
        for(int j = i+1; j < A.size()-1; ++j)
        {
            int maxc = A[i] + A[j]; // A[i] and A[j] are 2 smaller sides of triangle
            
            int idx = lower_bound(A.begin(), A.end(), maxc) - A.begin();
            --idx;
            
            ans += idx-j;
            ans %= MOD;
        }
    }
    return ans;
}
