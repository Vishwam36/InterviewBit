// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/knight-on-chess-board/
// Good question
// Ref : https://www.youtube.com/watch?v=FhwNdxnb738

struct cell
{
    int x;
    int y;
    int dist;
    
    cell() {}
    cell(int x, int y, int dist) : x(x), y(y), dist(dist) {}
};

bool isValidMove(int x, int y, int n, int m)
{
    if(x >= 0 && x < n && y >= 0 && y < m)
        return true;
    
    return false;
}

int Solution::knight(int n, int m, int x1, int y1, int x2, int y2) 
{
    int dx[] = {-1, -2, -1, -2, 1, 2, 1, 2};
    int dy[] = {2, 1, -2, -1, 2, 1, -2, -1};
    
    cell src(x1-1, y1-1, 0);
    
    queue<cell> q;
    q.push(src);
    
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    visited[x1-1][y1-1] = true;
    
    int x = 0, y = 0, dist = 0;
    while(!q.empty())
    {
        cell c = q.front();
        q.pop();
        
        if(c.x == x2-1 && c.y == y2-1)
            return c.dist;
        
        for(int i = 0; i < 8; ++i)
        {
            x = c.x + dx[i];
            y = c.y + dy[i];
            dist = c.dist;
            
            if(isValidMove(x, y, n, m) && !visited[x][y])
            {
                visited[x][y] = true;
                cell temp(x, y, dist+1);
                q.push(temp);
            }
        }
    }
    return -1;
}
