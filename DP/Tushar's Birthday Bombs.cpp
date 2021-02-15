// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/tushars-birthday-bombs/
// Tricky

vector<int> Solution::solve(int A, vector<int> &B) 
{
    int n = B.size(), min = B[0], minIndex = 0, prev = INT_MAX;
    vector<pair<int, int> > newB;
    for(int i = 0; i < n; ++i)
    {
        if(prev > B[i])
        {
            newB.push_back({B[i], i});
            minIndex = i;
            min = B[i];
            prev = B[i];
        }
    }
    
    int kicks = A / min;
    
    vector<int> v(kicks, minIndex);
    
    int currPain = min * kicks;
    int j = 0;
    
    for(int i = 0; i < newB.size(); ++i)
    {
        if(newB[i].first == min)
            break;
        
        while(currPain - min + newB[i].first <= A)
        {
            if(j >= v.size())
                return v;
            
            v[j] = newB[i].second;
            ++j;
            
            currPain = currPain - min + newB[i].first;
        }
    }
    return v;
}
