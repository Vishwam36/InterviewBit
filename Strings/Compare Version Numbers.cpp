// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/compare-version-numbers/
// nice problem

int Solution::compareVersion(string A, string B) 
{
    string numA, numB;
    
    for(int i = 0,  j = 0; (i < A.size() || j < B.size());)
    {
        numA = "";
        numB = "";
        
        // pass the initial zeros
        while(i < A.size() && A[i] == '0')
        {
            i++;
        }
        while(i < A.size() && A[i] != '.')
        {
            numA += A[i];
            ++i;
        }
        
        // pass the initial zeros
        while(j < B.size() && B[j] == '0')
        {
            j++;
        }
        while(j < B.size() && B[j] != '.')
        {
            numB += B[j];
            ++j;
        }
        
        if(numA != numB)
        {
            if(numA.size() == numB.size())
            {
                return (numA.compare(numB) > 0 ? 1 : -1);
            }
            return (numA.size() > numB.size() ? 1 : -1);
        }
        
        ++i;
        ++j;
    }
    return 0;
}
