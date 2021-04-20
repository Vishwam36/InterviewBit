// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/useful-extra-edges/
// Try if you want to practice dijkstra
/*
Problem Description

Given a graph of A nodes. Also given the weighted edges in the form of array B.
You are also given starting point C and destination point D.
Also given are some extra edges in the form of vector E.
You need to find the length of the shortest path from C to D if you can use maximum one road from the given roads in E.
All roads are one way ie they go from B[i][0] to B[i][1].

Problem Constraints
1 <= A <= 100000
1 <= |B| <= 100000
1 <= C, D <= A
1 <= |E| <= 300

All lengths of the roads lie between 1 and 1000.

Input Format
First argument is the integer A.
Second argument is the vector of vectors B.
Third argument is the integer C.
Fourth argument is the integer D.
Fifth argument is the vector of vectors E.

Output Format
Return -1 if C is not reachable from D. Else return the shortest distance between them.

Example Input
Input 1:
 A = 3
B = [   [1, 2, 1]
        [2, 3, 2]
    ]
C = 1
D = 3
E = [   [1, 3, 2]
    ]

Input 2:
 A = 4
B = [   [1, 2, 1]
        [2, 3, 2]
        [3, 1, 4]
    ]
C = 1
D = 4
E = [   [1, 3, 2]
    ]

Example Output
Output 1:
 2
Output 2:
 -1


Example Explanation
Explanation 1:

 Use the direct edge from 1 to 3. It has shortest path from 1 to 3.
Explanation 2:

 4 cannot be reached from 1.
*/

int dijkstra(int A, vector<pair<int, int> > v[], int C, int D)
{
    int dist[A+1];
    bool vis[A+1];
    
    for(int i = 1; i <= A; ++i)
    {
        dist[i] = INT_MAX;
        vis[i] = 0;
    }
    
    dist[C] = 0;
    
    priority_queue<pair<int, int> , vector<pair<int, int> > , greater<pair<int, int> > > pq;
    pq.push({0, C});
    
    while(!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        
        if(vis[p.second])
            continue;
        
        vis[p.second] = 1;
        
        for(int i = 0; i < v[p.second].size(); ++i)
        {
            pair<int, int> child = v[p.second][i];
            
            if(vis[child.first])
                continue;
            
            if(child.second + p.first < dist[child.first])
            {
                dist[child.first] = child.second + p.first;
                pq.push({dist[child.first], child.first});
            }
        }
    }
    return dist[D];
}

int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) 
{
    int minPath = INT_MAX;
    vector<pair<int, int> > adj[A+1];
    for(int i = 0; i < B.size(); ++i)
        adj[B[i][0]].push_back({B[i][1], B[i][2]});
    
    for(int i = 0; i < E.size(); ++i)
    {
        if(E[i][0] > A || E[i][1] > A)
            continue;
        
        adj[E[i][0]].push_back({E[i][1], E[i][2]});
        adj[E[i][1]].push_back({E[i][0], E[i][2]});
        
        minPath = min(minPath, dijkstra(A, adj, C, D));
        
        adj[E[i][0]].pop_back();
        adj[E[i][1]].pop_back();
    }
    
    if(minPath == INT_MAX)
        return -1;
    
    return minPath;
}
