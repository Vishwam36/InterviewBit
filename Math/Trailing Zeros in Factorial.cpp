// By vishwam Shriram Mundada
// https://www.interviewbit.com/problems/trailing-zeros-in-factorial/
// New concept
// ref : https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
/*
The idea is to consider prime factors of a factorial n. A trailing zero is always produced by prime factors 2 and 5. 
If we can count the number of 5s and 2s, our task is done. Consider the following examples.
n = 5: There is one 5 and 3 2s in prime factors of 5! (2 * 2 * 2 * 3 * 5). So a count of trailing 0s is 1.
n = 11: There are two 5s and eight 2s in prime factors of 11! (2^8 * 3^4 * 5^2 * 7). So the count of trailing 0s is 2.
 
We can easily observe that the number of 2s in prime factors is always more than or equal to the number of 5s. 
So if we count 5s in prime factors, we are done.
A simple way is to calculate floor(n/5). For example, 7! has one 5, 10! has two 5s. 
It is not done yet. Numbers like 25, 125, etc have more than one 5. 
For example, if we consider 28! we get one extra 5 and the number of 0s becomes 6. 
Handling this is simple, first, divide n by 5 and remove all single 5s, then divide by 25 to remove extra 5s, and so on. 
Following is the summarized formula for counting trailing 0s. 
Trailing 0s in n! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) + ....
*/

int Solution::trailingZeroes(int A) 
{
    int i = 5, count = 0;
    
    while(i <= A)
    {
        count += A / i;
        i *= 5;
    }
    
    return count;
}
