// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/subset/
// Good question

void rec(int index, vector<int> &temp, vector<int> A, vector<vector<int> > &v)
{
    v.push_back(temp);
    
    for(int i = index; i < A.size(); ++i)
    {
        temp.push_back(A[i]);
        rec(i+1, temp, A, n, v);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A)
{
    sort(A.begin(), A.end());
    vector<vector<int> > v;
    vector<int> temp;
    rec(0, temp, A, v);
    return v;
}
