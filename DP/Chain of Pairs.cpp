// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/chain-of-pairs/
// similar to "Longest Increasing Subsequence"

int Solution::solve(vector<vector<int> > &A) 
{
    vector<vector<int> > v({A[0]});
    
    for(int i = 1; i < A.size(); ++i)
        if(A[i][0] > v.back()[1])
            v.push_back(A[i]);
        
        else if(A[i][1] < v[0][1])
                v[0] = A[i];
        
        else
            for(int j = 0; j < v.size()-1; ++j)
                if(v[j][1] < A[i][0] && A[i][1] < v[j+1][1])
                    v[j+1] = A[i];
    
    return v.size();
}
