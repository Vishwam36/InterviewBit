// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/vowel-and-consonant-substrings/
// Easy

/*
Problem Description
Given a string A consisting of lowercase characters.
You have to find the number of substrings in A which starts with vowel and end with consonants or vice-versa.
Return the count of substring modulo 109 + 7.

Problem Constraints
1 <= |A| <= 105
A consists only of lower-case characters.

Input Format
First argument is an string A.

Output Format
Return a integer denoting the the number of substrings in A which starts with vowel and end with consonants or vice-versa with modulo 109 + 7.

Example Input
Input 1:
 A = "aba"

Input 2:
 A = "a"

Example Output
Output 1:
 2

Output 2:
 0

Example Explanation
Explanation 1:
 Substrings of S are : [a, ab, aba, b, ba, a]Out of these only 'ab' and 'ba' satisfy the condition for special Substring. So the answer is 2.

Explanation 2:
 No possible substring that start with vowel and end with consonant or vice-versa.
*/

const long long MOD = 1000000007;

bool isVovel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int Solution::solve(string A) 
{
    vector<int> vovel(A.size(), 0), conso(A.size(), 0);
    
    if(isVovel(A.back()))
        vovel.back()++;
    else
        conso.back()++;
    for(int i = A.size()-2; i >= 0; --i)
    {
        vovel[i] = vovel[i+1];
        conso[i] = conso[i+1];
        
        if(isVovel(A[i]))
            vovel[i]++;
        else
            conso[i]++;
    }
    
    long long ans = 0;
    for(int i = 0; i < A.size()-1; ++i)
    {
        if(isVovel(A[i]))
            ans += conso[i];
        else
            ans +=  vovel[i];
        
        ans %= MOD;
    }
    return ans;
}
