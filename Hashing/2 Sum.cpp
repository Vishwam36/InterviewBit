// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/2-sum/
// simple

vector<int> Solution::twoSum(const vector<int> &A, int B) 
{
    vector<int> v;
    map<int, int> m;
    
    for(int i = 0; i < A.size(); ++i)
    {
        int k = B - A[i];
        
        if(m.find(k) != m.end())
        {

            v.push_back(m[k]+1);
            v.push_back(i+1);
            return v;
        }
        else if(m.find(A[i]) == m.end())
        {
            m[A[i]] = i;
        }
    }
    return v;
}
