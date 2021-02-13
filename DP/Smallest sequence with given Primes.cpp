// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/
// Simple

vector<int> Solution::solve(int A, int B, int C, int D) 
{
    vector<int> v;
    
    if(D == 0)
        return v;
    
    set<int> s;
    s.insert(A);
    s.insert(B);
    s.insert(C);
    
    while(1)
    {
        int temp = *s.begin();
        v.push_back(temp);
        
        if(v.size() == D)
            break;
            
        s.erase(s.begin());
        
        s.insert(temp * A);
        s.insert(temp * B);
        s.insert(temp * C);
        
    }
    return v;
}
