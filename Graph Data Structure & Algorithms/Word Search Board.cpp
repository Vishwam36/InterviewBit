// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/word-search-board/
// Easy but I dont know why bfs gives partial correct 

int n, m;
int ver[] = {0, 0, -1, 1};
int hor[] = {-1, 1, 0, 0};

bool isValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool rec(int x, int y, vector<string> &A, string B, int index)
{
    if(index == B.size()-1)
        return 1;
    
    for(int i = 0; i < 4; ++i)
    {
        int newX = x + hor[i];
        int newY = y + ver[i];
        
        if(isValid(newX, newY) && A[newX][newY] == B[index+1] && rec(newX, newY, A, B, index+1))
            return 1;
    }
    return 0;
}

int Solution::exist(vector<string> &A, string B) 
{
    n = A.size(), m = A[0].size();
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(A[i][j] == B[0] && rec(i, j, A, B, 0))
                return 1;
    
    return 0;
}
