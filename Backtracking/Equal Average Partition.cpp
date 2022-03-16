// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/equal-average-partition/
// Good

/*
Given an array A with non negative numbers, divide the array into two parts such that the average of both the parts is equal.

Return both parts (If exist). If there is no solution. return an empty list.

NOTE:
If a solution exists, you should return a list of exactly 2 lists of integers A and B which follow the following condition :
numElements in A <= numElements in B
If numElements in A = numElements in B, then A is lexicographically smaller than B ( https://en.wikipedia.org/wiki/Lexicographical_order )

If multiple solutions exist, return the solution where length(A) is minimum. If there is still a tie, return the one where A is lexicographically smallest.

Array will contain only non negative numbers.

**Input Format**
First andonly argument is an integer array A.

**Output Format**
Return 2D array consisting of two rows where each row denoted a partition.

**Example Input**
Input 1:
 A = [1 7 15 29 11 9]
 
Example Output
Output 1:
 [9 15] [1 7 11 29]
 
Example Explanation
Explanation 1:
 The average of part is (15+9)/2 = 12, average of second part elements is (1 + 7 + 11 + 29) / 4 = 12
*/

bool possible(int idx, int sz, vector<int> &a, vector<int> &v1, vector<int> &v2, int sum)
{
    if(idx == a.size())
        return sz == 0 && sum == 0;
    if(sum > a.back() * sz)
        return false;
    if(sz == 0 && sum != 0)
        return false;
    
    if(sz > 0)
    {
        v1.push_back(a[idx]);
        if(sum - a[idx] >= 0 && possible(idx+1, sz-1, a, v1, v2, sum - a[idx]))
            return true;
        v1.pop_back();
    }

    v2.push_back(a[idx]);
    if(possible(idx+1, sz, a, v1, v2, sum))
        return true;
    v2.pop_back();
    
    return false;
}

vector<vector<int> > Solution::avgset(vector<int> &a)
{
    int n = a.size();
    int total = 0;
    for(auto& num : a)
        total += num;
    
    double avg = (double)total/n;
    
    sort(a.begin(), a.end());
    vector<int> v1, v2;
    vector<vector<int> > ans;
    for(int n1 = 1; n1 <= n/2; ++n1)
    {
        if(abs((round(avg*n1)) - avg*n1) < 1e-3 && ((total*n1) % n == 0) 
        && possible(0, n1, a, v1, v2, (round)(avg*n1)))
        {
            ans.push_back(v1);
            ans.push_back(v2);
            break;
        }
    }
    
    return ans;
}
