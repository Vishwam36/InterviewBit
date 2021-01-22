// By vishwam Shriram Mundada
// https://www.interviewbit.com/problems/matrix-search/


// little trick used
// its easy if thing deeply and draw on paper
/*
We are imagining it as 1D array
mid will be calculated as 1D array
but we need to to calculate actual position of that in 2D matrix
mid / cols will give the row in ehich mid lies
mid % cols will calculate how far is the mid from 0th index in that row
*/
int Solution::searchMatrix(vector<vector<int> > &A, int B) 
{
    int rows = A.size(), cols = A[0].size();
    int l = 0, r = (rows * cols) - 1, mid = 0, mid_element = 0;
    
    while(l <= r)
    {
        mid = (l + r) / 2;
        mid_element = A[mid / cols][mid % cols];
        
        if(mid_element == B)
            return 1;
            
        else if(mid_element < B)
            l = mid + 1;
            
        else
            r = mid - 1;
    }
    return 0;
}


// simple solution -> first get the row in which B lies and then search in that row
// get the row in which B lies
int getReqRow(vector<vector<int> > A, int B)
{
    int rows = A.size(), cols = A[0].size();
    
    int l = 0, r = rows - 1, mid = 0, reqRow = -1;
    
    while(r - l > 1)
    {
        mid = (l + r) / 2;
        
        if(A[mid][0] <= B && A[mid][cols - 1] >= B)
        {
            reqRow = mid;
            break;
        }
        
        else if(A[mid][0] > B)
            r = mid;
        
        else
            l = mid;
    }
    
    if(reqRow == -1)
    {
        if(A[l][0] <= B && A[l][cols - 1] >= B)
            reqRow = l;
    
        else
            reqRow = r;
    }
    
    return reqRow;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) 
{
    int reqRow = getReqRow(A, B);
    
    if(upper_bound(A[reqRow].begin(), A[reqRow].end(), B)
    - lower_bound(A[reqRow].begin(), A[reqRow].end(), B) == 0)
        return 0;

    else
        return 1;
}
