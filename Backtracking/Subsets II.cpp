// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/subsets-ii/
// Similar to subsets problem
/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]
*/

void rec(vector<int> A, vector<int> temp, int index, set <vector<int> > &s)
{
    if(index >= A.size())
    {
        s.insert(temp);
        return;
    }
    
    rec(A, temp, index+1, s);
    temp.push_back(A[index]);
    rec(A, temp, index+1, s);
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) 
{
    sort(A.begin(), A.end());
    set<vector<int> > :: iterator it;
    
    set <vector<int> > s;
    vector<vector<int> > ans;
    vector<int> temp;
    rec(A, temp, 0, s);
    
    it = s.begin();
    while(it != s.end())
    {
        ans.push_back(*it);
        it++;
    }
    return ans;
}
