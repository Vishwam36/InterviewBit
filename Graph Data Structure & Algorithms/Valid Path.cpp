// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/valid-path/
// Easy with little maths

int ver[] = {0, 0, 1, 1, 1, -1, -1, -1};
int hor[] = {-1, 1, -1, 0, 1, -1, 0, 1};

bool isValid(int x, int y, vector<vector<bool> > &rect)
{
    return x < rect.size() && x >= 0 && y < rect[0].size() && y >= 0 && rect[x][y] == 0;
}

string Solution::solve(int x, int y, int n, int r, vector<int> &a, vector<int> &b) 
{
    vector<vector<bool> > rect(x+1, vector<bool>(y+1, false));

    for(int i = 0; i <= x; ++i)
        for(int j = 0; j <= y; ++j)
            for(int k = 0; k < n; ++k)
                if(sqrt(pow(a[k]-i, 2) + pow(b[k]-j, 2)) <= r)
                {
                    rect[i][j] = 1;
                    break;
                }
    
    if(rect[0][0] == 1 || rect[x][y] == 1)
        return "NO";
    
    queue<pair<int, int> > q;
    q.push({0, 0});
    rect[0][0] = 1;
    
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        
        int xx = p.first;
        int yy = p.second;
        
        if(xx == x && yy == y)
            return "YES";
        
        for(int i = 0; i < 8; ++i)
        {
            int newX = xx + hor[i];
            int newY = yy + ver[i];
            
            if(isValid(newX, newY, rect))
            {
                q.push({newX, newY});
                rect[newX][newY] = 1;
            }
        }
    }
    return "NO";
}
