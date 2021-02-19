// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/zigzag-string/
// Decent problem
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R

And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows
*/

string Solution::convert(string A, int B) 
{
    int n = A.size();
    
    if(B <= 1 || n <= 1)
        return A;
    
    string ans = "";
    int diff = 0, i = 0;
    bool flag = false;
    
    while(diff < B)
    {
        flag = false;
        i = diff;
        while(i < n)
        {
            if(diff == 0 || diff == B-1)
            {
                ans += A[i];
                i += (2*(B-1));
            }
            else
            {
                if(flag == false)
                {
                    ans += A[i];
                    i += (B - 1 - diff) * 2;
                    flag = true;
                }
                else
                {
                    ans += A[i];
                    i += diff * 2;
                    flag = false;
                }
            }
        }
        diff++;
    }
    return ans;
}
