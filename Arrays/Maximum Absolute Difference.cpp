// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/maximum-absolute-difference/
// Easy

/*
You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,
A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.
*/

// (+/-) (A[i] + i) (+/-) (A[i] - i)

//Case 1 :  (A[i] + i) + (A[i] - i)
//Case 2 : -(A[i] + i) + (A[i] - i)
//Case 3 : -(A[i] + i) - (A[i] - i)
//Case 4 :  (A[i] + i) - (A[i] - i)

//Find the values corresponding to max and min of (A[i] + i) & (A[i] - i)

int Solution::maxArr(vector<int> &A)
{
    int min1 = INT_MAX, max1 = INT_MIN; // type : A[i]+i
    int min2 = INT_MAX, max2 = INT_MIN; // type : A[i]-i
    
    for(int i = 0; i < A.size(); ++i)
    {
        min1 = min(min1, A[i]+i);
        max1 = max(max1, A[i]+i);
        
        min2 = min(min2, A[i]-i);
        max2 = max(max2, A[i]-i);
    }
    
    return max(max1-min1, max2-min2);
}
