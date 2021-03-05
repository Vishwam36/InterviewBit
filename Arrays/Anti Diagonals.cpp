// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/anti-diagonals/
// App 2 is good
/*
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]
*/

// App 1 :
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) 
{
    int r = A.size(), c = A[0].size();
    vector<vector<int> > ans;
    
    for(int i = 0; i < c; ++i)
    {
        vector<int> temp;
        
        for(int j = 0, k = i; j < r && k >= 0; ++j, --k)
            temp.push_back(A[j][k]);
        
        ans.push_back(temp);
    }
    
    for(int i = 1; i < r; ++i)
    {
        vector<int> temp;
        
        for(int j = i, k = c-1; j < r && k >= 0; ++j, --k)
            temp.push_back(A[j][k]);
        
        ans.push_back(temp);
    }
    
    return ans;
}

// App 2 :
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) 
{
    int r = A.size(), c = A[0].size();
    vector<vector<int> > ans(r+c-1);
    
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            ans[i+j].push_back(A[i][j]);
    
    return ans;
}
