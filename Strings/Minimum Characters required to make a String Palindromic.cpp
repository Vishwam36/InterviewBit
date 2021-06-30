// By vishwam Shriram Mundada
// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
// Nice problem, new concept
// refer KMP algo

/*
Given an string A. The only operation allowed is to insert characters in the beginning of the string.

Find how many minimum characters are needed to be inserted to make the string a palindrome string.

Input Format
The only argument given is string A.

Output Format
Return the minimum characters that are needed to be inserted to make the string a palindrome string.

For Example
Input 1:
    A = "ABC"
Output 1:
    2
    Explanation 1:
        Insert 'B' at beginning, string becomes: "BABC".
        Insert 'C' at beginning, string becomes: "CBABC".

Input 2:
    A = "AACECAAAA"
Output 2:
    2
    Explanation 2:
        Insert 'A' at beginning, string becomes: "AAACECAAAA".
        Insert 'A' at beginning, string becomes: "AAAACECAAAA".
*/

int Solution::solve(string A) 
{
    string s = A;
    reverse(A.begin(), A.end());
    s = s + "$" + A;

    vector<int> p(s.size(), 0);
    
    for(int i = 1; i < s.size(); ++i)
    {
        int j = p[i-1];
        while(j > 0 && s[i] != s[j])
            j = p[j-1];
        
        if(s[i] == s[j])
            ++j;
        
        p[i] = j;
    }
    
    return A.size() - p.back();
}
