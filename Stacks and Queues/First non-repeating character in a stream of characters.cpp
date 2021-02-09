// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/
// simple

string Solution::solve(string A) 
{
    string B;
    queue <char> q;
    int n = A.size();
    int count[26];
    memset(count, 0, sizeof(count));
    for(int i = 0; i < n; ++i)
    {
        count[A[i] - 'a']++;
        q.push(A[i]);
        
        while(!q.empty())
        {
            if(count[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            else
            {
                B += q.front();
                break;
            }
        }
        if(q.empty())
        {
            B += "#";
        }
    }
    return B;
}
