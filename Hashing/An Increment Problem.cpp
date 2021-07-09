// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/an-increment-problem/
// Easy

/*
Problem Description
Given a stream of numbers A. On arrival of each number, you need to increase its first occurence by 1 and include this in the stream.

Return the final stream of numbers.

Problem Constraints
1 <= |A| <= 100000
1 <= A[i] <= 10000

Input Format
First and only argument is the array A.

Output Format
Return an array, the final stream of numbers.

Example Input
Input 1:
A = [1, 1]
Input 2:
A = [1, 2]

Example Output
Output 1:
[2, 1]
Output 2:
[1, 2]

Example Explanation
Explanation 1:
 On arrival of the second element, the other element is increased by 1.
Explanation 2:
No increases are to be done.
*/

vector<int> Solution::solve(vector<int> &A)
{
    unordered_map<int, set<int> > m;
    
    vector<int> ans;
    for(int i = 0; i < A.size(); ++i)
    {
        if(m.find(A[i]) != m.end())
        {
            int idx = *(m[A[i]].begin()); // find smallest index of A[i]
            ans[idx]++;
            
            m[A[i]].erase(m[A[i]].begin()); // remove that index
            if(m[A[i]].size() == 0)
                m.erase(A[i]);
            
            m[ans[idx]].insert(idx); // add index for new element
        }
        ans.push_back(A[i]);
        m[A[i]].insert(i);
    }
    return ans;
}
