// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/word-ladder-i/
// Good question
/*
Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:

You must change exactly one character in every transformation.
Each intermediate word must exist in the dictionary.

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

Input 1:
    A = "hit"
    B = "cog"
    C = ["hot", "dot", "dog", "lot", "log"]

Output 1:
    5

Explanation 1:
    "hit" -> "hot" -> "dot" -> "dog" -> "cog"
*/

int Solution::solve(string A, string B, vector<string> &C) 
{
    set<string> notVisited; // set of strings which are yet to visit
    for(int i = 0; i < C.size(); ++i)
        if(C[i] != A)
            notVisited.insert(C[i]);
    
    notVisited.insert(B);
    
    queue<pair<string, int> > q;
    q.push({A, 0});

    while(!q.empty())
    {
        pair<string, int> p = q.front();
        string curr = p.first;
        int level = p.second;
        q.pop();
        
        if(curr == B)
            return level+1;
        
        for(int i = 0; i < curr.size(); ++i)
        {
            string temp = curr;
            for(char ch = 'a'; ch <= 'z'; ++ch)
            {
                temp[i] = ch;
                // if curr and temp with one replaced character are same then continue(no duplicates)
                if(temp == curr)
                    continue;
                
                // if temp with one charcter replaced is in notVisited set then push it to queue
                if(notVisited.find(temp) != notVisited.end())
                {
                    q.push({temp, level+1});
                    notVisited.erase(temp);
                }
            }
        }
    }
    return 0;
}
