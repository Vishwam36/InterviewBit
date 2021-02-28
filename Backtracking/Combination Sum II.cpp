// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/combination-sum-ii/
// Good question, very similar to Combination Sum, only one number is not allowed multiple times

void rec(int index, vector<int> temp, vector<vector<int> > &v, vector<int> A, int B)
{
    if(B <= 0)
    {
        if(B == 0)
        {
            if(v.size() == 0)
            {
                v.push_back(temp);
            }
            
            else
            {
                bool flag = false;
                for(int i = 0; i < v.size(); ++i)
                    if(v[i] == temp)
                        flag = true;
                        
                if(flag == false)
                    v.push_back(temp);
            }
        }
        return;
    }
    
    if(index >= A.size())
        return;
    
    for(int i = index; i < A.size(); ++i)
    {
        temp.push_back(A[i]);
        rec(i+1, temp, v, A, B-A[i]);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B)
{
    vector<vector<int> > v;
    sort(A.begin(), A.end());
    vector<int> temp;
    
    rec(0, temp, v, A, B);
    
    return v;
}
