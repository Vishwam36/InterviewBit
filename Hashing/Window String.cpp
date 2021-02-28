// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/window-string/
// Good question, hashing + two pointers
/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.
Example :
S = "ADOBECODEBANC"
T = "ABC"
*/

string Solution::minWindow(string A, string B) 
{
    if(B.size() == 0 || A.size() < B.size())
        return "";
    
    string ans = "";
    
    int freq[256]={0};
    
    for(int i = 0; i < B.size(); ++i)
        freq[B[i]]++;
    
    int newFreq[256]={0};
    
    int count = 0, currSize = 0, minSize = INT_MAX;
    
    for(int i = 0, j = 0; j < A.size(); ++j)
    {
        if(freq[A[j]] == 0)
            continue;
            
        newFreq[A[j]]++;
        
        if(newFreq[A[j]] <= freq[A[j]])
            count++;
            
        if(count == B.size())
        {
            while(freq[A[i]] == 0 || freq[A[i]] < newFreq[A[i]])
            {
                if(newFreq[A[i]] > freq[A[i]])
                    newFreq[A[i]]--;
                
                i++;
            }
            
            currSize = j - i + 1;
            if(currSize < minSize)
            {
                minSize = currSize;
                ans.clear();
                ans.append(A.begin()+i, A.begin()+j+1);
            }
        }
    }
    return ans;
}
