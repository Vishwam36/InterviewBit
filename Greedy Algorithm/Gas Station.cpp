// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/gas-station/
// Tricky

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) 
{
    int overall = 0, fuel = 0, start = 0;
    
    for(int i = 0; i < A.size(); ++i)
    {
        overall += A[i] - B[i];
        fuel += A[i] - B[i];
        if(fuel < 0)
        {
            fuel = 0;
            start = i+1;
        }
    }
    
    // overall checks whether solution is possible or not
    // overall = sum of gas at all stations - sum of gas required
    if(overall >= 0) 
        return start;
    
    return -1;
}
