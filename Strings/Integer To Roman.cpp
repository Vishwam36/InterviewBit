// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/integer-to-roman/
// decent question
// Ref : https://www.geeksforgeeks.org/converting-decimal-number-lying-between-1-to-3999-to-roman-numerals/
/*
Algorithm to convert decimal number to Roman Numeral 
Compare given number with base values in the order 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1. 
Base value which is just smaller or equal to the given number will be the initial base value (largest base value).
Divide the number by its largest base value, the corresponding base symbol will be repeated quotient times, 
the remainder will then become the number for future division and repetitions.
The process will be repeated until the number becomes zero.
*/

string Solution::intToRoman(int A) 
{
    string ans = "";
    
    int nums[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string s[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    
    int i = 12, cnt = 0;
    
    while(A > 0)
    {
        cnt = A / nums[i];
        A = A % nums[i];
        
        while(cnt--)
            ans += s[i];
        
        --i;
    }
    return ans;
}
