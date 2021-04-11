// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/
// Good question
// But why https://github.com/Vishwam36/SPOJ/blob/main/Graph%20Data%20Structure%20%26%20Algorithms/ONEZERO%20-%20Ones%20and%20zeros.cpp is not working on Interviewbit
// Ref for another similar approach : https://www.youtube.com/watch?v=sdTubUR99OA

string Solution::multiple(int A) 
{
    if(A == 0 || A == 1)
        return to_string(A);
    
    int pre[A+1]; // previous remainder
    bool flag[A+1]; // visited the remainder or not
    int val[A+1]; // whats the value added for that remainder 0 or 1
    
    memset(pre, -1, sizeof(pre));
    memset(flag, 0, sizeof(flag));
    memset(val, -1, sizeof(flag));
    
    queue<int> q;
    q.push(1);
    flag[1] = 1;
    val[1] = 1;
    pre[1] = -1;
    
    while(!q.empty())
    {
        int r = q.front();
        q.pop();
        
        if(r == 0)
        {
            string s = "";
            while(r != -1)
            {
                s.push_back(val[r] + '0');
                r = pre[r];
            }
            reverse(s.begin(), s.end());
            return s;
        }
        
        int r0 = (r*10) % A;
        int r1 = (r*10 + 1) % A;
        
        if(!flag[r0])
        {
            flag[r0] = 1;
            pre[r0] = r;
            val[r0] = 0;
            q.push(r0);
        }
        if(!flag[r1])
        {
            flag[r1] = 1;
            pre[r1] = r;
            val[r1] = 1;
            q.push(r1);
        }
    }
}
