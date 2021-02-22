// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/anagrams/
// Simple 
/*
App 1 : We can calculate frequency array of characters for all strings and check for same arrays
        Anagrams will have same frequency array
App 2 : We can sort all strings
        Anagrams will have same sorted strings
We are doing here App 1.
*/
vector<vector<int> > Solution::anagrams(const vector<string> &A) 
{
    int n = A.size();
    map<vector<int>, vector<int> > m;
    map<vector<int>, vector<int> > :: iterator it;
    
    for(int i = 0; i < n; ++i)
    {
        vector<int> freq(26, 0);
        for(int j = 0; j < A[i].size(); ++j)
        {
            freq[A[i][j] - 'a']++;
        }
        m[freq].push_back(i+1);
    }
    
    vector<vector<int> > v;
    for(it = m.begin(); it != m.end(); ++it)
        v.push_back(it -> second);
    
    return v;
}
