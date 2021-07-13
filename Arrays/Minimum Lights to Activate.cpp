// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/minimum-lights-to-activate/
// Decent, greedy

/*
Problem Description
There is a corridor in a Jail which is N units long. Given an array A of size N. The ith index of this array is 0 if the light at ith position is faulty 
otherwise it is 1.
All the lights are of specific power B which if is placed at position X, it can light the corridor from [ X-B+1, X+B-1].
Initially all lights are off.
Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.

Problem Constraints
1 <= N <= 1000
1 <= B <= 1000

Input Format
First argument is an integer array A where A[i] is either 0 or 1.
Second argument is an integer B.

Output Format
Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.

Example Input
Input 1:
A = [ 0, 0, 1, 1, 1, 0, 0, 1].
B = 3

Input 2:
A = [ 0, 0, 0, 1, 0].
B = 3

Example Output
Output 1:
2

Output 2:
-1

Example Explanation
Explanation 1:
In the first configuration, Turn on the lights at 3rd and 8th index.
Light at 3rd index covers from [ 1, 5] and light at 8th index covers [ 6, 8].

Explanation 2:
In the second configuration, there is no light which can light the first corridor.
*/

// TC : O(N*B)

int Solution::solve(vector<int> &A, int B) 
{
    int count = 0, n = A.size();
    for(int i = 0; i < n; ++i)
    {
        bool flag = 0;
        for(int j = min(n-1, i+B-1); j >= max(0, i-B+1); --j)
        {
            if(A[j] == 1)
            {
                count++;
                i = j+B-1;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            return -1;
    }
    return count;
}

// TC : O(N)


int Solution::solve(vector<int> &A, int B) 
{
    int ans = 0;
    int lit = -1, tempLit = -1;
    for(int i = 0; i < A.size(); ++i)
    {
        if(A[i] == 1)
        {
            int leftLimit = i-B+1;
            int rightLimit = i+B-1;
            
            if(leftLimit <= lit+1)
            {
                tempLit = rightLimit;
            }
            else
            {
                ans++;
                if(lit == tempLit || (tempLit - (2*B)) > lit)
                    return -1;
                
                lit = tempLit;
                tempLit = rightLimit;
            }
        }
    }
    
    if((lit < (int)A.size()-1) && (lit != tempLit))
        ans++;
    
    return ans;
}
