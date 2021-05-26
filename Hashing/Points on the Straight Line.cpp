// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/points-on-the-straight-line/
// Decent, Maths

/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Sample Input :
(1, 1)
(2, 2)

Sample Output :
2

You will be given 2 arrays X and Y. Each point is represented by (X[i], Y[i])
*/

vector<double> get_mc(int x1, int y1, int x2, int y2)
{
    double m;
    if(x1 == x2) // if line is like x = 10, i.e infinte slope
        m = INT_MAX;
    else 
        m = (double)(y2-y1)/(x2-x1);
    
    double c = y1 - m*x1;
    return {m, c};
}

int Solution::maxPoints(vector<int> &A, vector<int> &B)
{
    if(A.size() <= 2)
        return A.size();
    
    // y = mx + c 
    // each line will have unique m and c, So hash with m and c
    map<vector<double>, set<vector<int> > > m;
    for(int i = 0; i < A.size(); ++i)
    {
        int x1 = A[i], y1 = B[i];
        for(int j = i+1; j < A.size(); ++j)
        {
            int x2 = A[j], y2 = B[j];
            
            vector<double> mc = get_mc(x1, y1, x2, y2);
            
            // even if co-ordinates are same we have to consider them different if indexes are different
            // Therefore I have taken third value as index
            m[mc].insert({x1, y1, i});
            m[mc].insert({x2, y2, j});
        }
    }
    
    int ans = 0;
    for(auto it = m.begin(); it != m.end(); ++it)
        ans = max(ans, (int)(it->second).size());
    
    return ans;
}
