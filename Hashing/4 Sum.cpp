// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/4-sum/
// Good Question

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) 
{
    vector<vector<int> > v;
    vector<int> temp;
    
    sort(A.begin(), A.end());
    int n = A.size(), i = 0, j = 0, l = 0, r = 0, ab = 0, cd = 0, sum = 0;
    
    while(i < n-3)
    {
        j = i+1;
        while(j < n-2)
        {
            l = j + 1;
            r = n-1;
            ab = A[i] + A[j];
            cd = B - ab;
            
            while(l < r)
            {
                sum = A[l] + A[r];
                if(cd == sum)
                {
                    temp = {A[i], A[j], A[l], A[r]};
                    v.push_back(temp);
                    temp.clear();
                    while(A[l] == A[l+1])
                    {
                        ++l;
                    }
                    while(A[r] == A[r-1])
                    {
                        --r;
                    }
                    ++l;
                    --r;
                }
                else if(sum < cd)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
            
            while(A[j] == A[j+1])
            {
                j++;
            }
            ++j;
        }
        
        while(A[i] == A[i+1])
        {
            ++i;
        }
        ++i;
    }
    
    return v;
}
