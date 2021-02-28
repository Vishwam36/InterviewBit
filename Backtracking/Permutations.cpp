// By vishwam Shriram Mundada
// https://www.interviewbit.com/problems/permutations/
// Good question
/*
Given a collection of numbers, return all possible permutations.
[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
*/

// App 1:
void rec(vector<int> A, vector<vector<int> > &ans, vector<int> temp, int n)
{
    if(temp.size() == n)
    {
        ans.push_back(temp);
        return;
    }
        
    for(int i = 0; i < A.size(); ++i)
    {
        temp.push_back(A[i]);
        
        vector<int> newA;
        for(int j = 0; j < A.size(); ++j)
            if(j != i)
                newA.push_back(A[j]);
        
        rec(newA, ans, temp, n);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) 
{
    vector<vector<int> > ans;
    vector<int> temp;
    rec(A, ans, temp, A.size());
    return ans;
}

// App 2:
void rec(vector<int> A, vector<vector<int> > &ans, int index)
{
    if(index >= A.size())
    {
        ans.push_back(A);
        return;
    }
        
    for(int i = index; i < A.size(); ++i)
    {
        swap(A[index], A[i]);
        rec(A, ans, index+1);
        swap(A[index], A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) 
{
    vector<vector<int> > ans;
    rec(A, ans, 0);
    return ans;
}
