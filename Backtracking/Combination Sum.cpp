// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/combination-sum/
// Good question 
// Ref : https://www.youtube.com/watch?v=irFtGMLbf-s&ab_channel=GoodTecher

void rec(int index, vector<int> temp, vector<int> A, int B, vector<vector<int> > &v)
{
    if(B <= 0)
    {
        if(B == 0)
            v.push_back(temp);
            
        return;
    }
    
    if(index >= A.size())
        return;
    
    for(int i = index; i < A.size(); ++i)
    {
        if(A[i] > B)
            return;
        
        temp.push_back(A[i]);
        rec(i, temp, A, B-A[i], v);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) 
{
    
    vector<vector<int> > v;
    sort(A.begin(), A.end());
    
    vector<int> newA, temp;
    
    newA.push_back(A[0]);
    for(int i = 1; i < A.size(); ++i)
        if(A[i-1] != A[i])
            newA.push_back(A[i]);
    
    rec(0, temp, newA, B, v);
    return v;
}
