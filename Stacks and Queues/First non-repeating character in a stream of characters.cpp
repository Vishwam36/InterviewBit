// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/
// simple

/*
Given a string A denoting a stream of lowercase alphabets. You have to make new string B.

B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append it at the end to B. 
If no non-repeating character is found then append '#' at the end of B.

Problem Constraints
1 <= length of the string <= 100000

Input Format
The only argument given is string A.

Output Format
Return a string B after processing the stream of lowercase alphabets A.

Example Input
Input 1:
 A = "abadbc"
 
Input 2:
 A = "abcabc"

Example Output
Output 1:
 "aabbdd"
 
Output 2:
 "aaabc#"

Example Explanation
Explanation 1:

    "a"      -   first non repeating character 'a'
    "ab"     -   first non repeating character 'a'
    "aba"    -   first non repeating character 'b'
    "abad"   -   first non repeating character 'b'
    "abadb"  -   first non repeating character 'd'
    "abadbc" -   first non repeating character 'd'
Explanation 2:

    "a"      -   first non repeating character 'a'
    "ab"     -   first non repeating character 'a'
    "abc"    -   first non repeating character 'a'
    "abca"   -   first non repeating character 'b'
    "abcab"  -   first non repeating character 'c'
    "abcabc" -   no non repeating character so '#'
*/

// TC : O(N)
// SC : O(26) (queue size will never exceed 26)

string Solution::solve(string A) 
{
    queue<char> q;
    vector<int> f(26, 0);
    
    for(int i = 0; i < A.size(); ++i)
    {
        if(f[A[i]-'a'] == 0)
            q.push(A[i]);
        
        f[A[i]-'a']++;
        
        while(!q.empty() && f[q.front()-'a'] > 1)
            q.pop();
        
        if(q.empty())
            A[i] = '#';
        else
            A[i] = q.front();
    }
    return A;
}
