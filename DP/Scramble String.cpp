// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/scramble-string/
// Good question
// MCM variation

/*
Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of A = “great”:

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that “rgeat” is a scrambled string of “great”.

Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that “rgtae” is a scrambled string of “great”.

Given two strings A and B of the same length, determine if B is a scrambled string of S.

Input Format:
The first argument of input contains a string A.
The second argument of input contains a string B.

Output Format:
Return an integer, 0 or 1:
    => 0 : False
    => 1 : True

Constraints:
1 <= len(A), len(B) <= 50

Examples:
Input 1:
    A = "we"
    B = "we"

Output 1:
    1

Input 2:
    A = "phqtrnilf"
    B = "ilthnqrpf"
    
Output 2:
    0
*/

map<pair<string, string>, bool> m;

bool rec(string a, string b)
{
    if(m.find({a, b}) != m.end() || m.find({b, a}) != m.end())
        return m[{a, b}] || m[{b, a}];
    
    if(a == b)
        return true;
    
    int n = a.size();
    bool ans = false;
    for(int i = 1; i < n; ++i)
    {
        bool ans1 = rec(a.substr(0, i), b.substr(n-i)) 
                    && rec(a.substr(i), b.substr(0, n-i));
        
        bool ans2 = rec(a.substr(0, i), b.substr(0, i))
                    && rec(a.substr(i), b.substr(i));
        
        ans = ans || (ans1 && ans2);
    }
    
    return m[{a, b}] = ans;
}

int Solution::isScramble(const string A, const string B) 
{
    m.clear();
    return rec(A, B);
}
