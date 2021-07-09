// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/n3-repeat-number/
// Good question
// General question : https://github.com/Vishwam36/GFG/blob/main/Arrays/Count%20More%20than%20n%20by%20k%20Occurences.cpp

/*
You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :
Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 
*/

// General question : https://github.com/Vishwam36/GFG/blob/main/Arrays/Count%20More%20than%20n%20by%20k%20Occurences.cpp

int numCount(int candidate, const vector<int> &A)
{
    int count = 0;
    for(auto num : A)
        if(num == candidate)
            count++;
    
    return count;
}

int Solution::repeatedNumber(const vector<int> &A)
{
    int n = A.size();
    pair<int, int> container1, container2; // {num, count}
    
    for(auto num : A)
    {
        if(container1.first == num)
            container1.second++;
        else if(container2.first == num)
            container2.second++;
        else
        {
            if(container1.second == 0)
                container1 = {num, 1};
            else if(container2.second == 0)
                container2 = {num, 1};
            else
            {
                container1.second--;
                container2.second--;
            }
        }
    }
    
    if(numCount(container1.first, A) > n/3)
        return container1.first;
    if(numCount(container2.first, A) > n/3)
        return container2.first;;
    return -1;
}
