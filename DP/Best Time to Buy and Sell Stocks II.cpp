// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/
// Simple
/*
Say you have an array, A, for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.

You may complete as many transactions as you like
*/

int Solution::maxProfit(const vector<int> &A) 
{
    int n = A.size();
    bool bought = false;
    int price = 0;
    int profit = 0;
    
    for(int i = 0; i < n-1; ++i)
    {
        if(bought == false)
        {
            if(A[i+1] > A[i])
            {
                bought = true;
                price = A[i];
            }
        }
        else
        {
            if(A[i+1] < A[i])
            {
                profit += A[i] - price;
                bought = false;
            }
        }
    }
    
    if(bought == true && A[n-1] > price)
        profit += A[n-1] - price;
    
    return profit;
}
