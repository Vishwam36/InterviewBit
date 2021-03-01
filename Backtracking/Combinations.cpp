// By vishwam Shriram Mundada
// https://www.interviewbit.com/problems/combinations/
// Decent
/*
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
*/

void rec(vector<vector<int> > &ans, vector<int> temp, int index, int n, int k)
{
    if(temp.size() == k)
    {
        ans.push_back(temp);
        return;
    }
    
    for(int i = index; i <= n; ++i)
    {
        temp.push_back(i);
        rec(ans, temp, i+1, n, k);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combine(int A, int B) 
{
    vector<vector<int> > ans;
    vector<int> temp;
    rec(ans, temp, 1, A, B);
    return ans;
}
