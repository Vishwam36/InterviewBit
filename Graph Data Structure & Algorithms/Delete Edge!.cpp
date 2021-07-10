// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/delete-edge/
// Decent

/*
Problem Description
Given a undirected tree with N nodes labeled from 1 to N.
Each node has a certain weight assigned to it given by an integer array A of size N.
You need to delete an edge in such a way that Product between sum of weight of nodes in one subtree with sum of weight of nodes in other subtree is maximized.
Return this maximum possible product modulo 109 + 7.

NOTE:
The tree is rooted at node labeled with 1.

Problem Constraints
2 <= N <= 105
1 <= A[i] <= 103

Input Format
First argument is an integer array A of size N denoting the weight of each node.
Second argument is a 2-D array B of size (N-1) x 2 denoting the edge of the tree.

Output Format
Return a single integer denoting the maximum product prossible of sum of weights of nodes in the two subtrees formed by deleting an edge with modulo 109 + 7.

Example Input
Input 1:
 A = [10, 5, 12, 6]
 B = [

        [1, 2]
        [1, 4]
        [4, 3]
     ]
Input 2:
 A = [11, 12]
 B = [

        [1, 2]
     ]

Example Output
Output 1:
 270
Output 2:
 132
 
Example Explanation
Explanation 1:
 Removing edge (1, 4) created two subtrees.
 Subtree-1 contains nodes (1, 2) and Subtree-2 contains nodes (3, 4)
 So product will be = (A[1] + A[2]) * (A[3] + A[4]) = 15 * 18 = 270
 
Explanation 2:
 Removing edge (1, 2) created two subtrees.
 Subtree-1 contains node (1) and Subtree-2 contains node (3)
 So product will be = (A[1]) * (A[2]) = 11 * 12 = 132
*/

int t;
long long MOD = 1000000007;

long long dfs(int src, vector<pair<int, int> > adj[], vector<int> &vis, vector<long long> &sum, vector<int> &A)
{
    vis[src] = t++;
    
    long long tempSum = 0;
    for(auto next : adj[src])
        if(vis[next.first] == 0)
            tempSum += dfs(next.first, adj, vis, sum, A);
    
    return sum[src] = tempSum + A[src];
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) 
{
    int n = A.size();
    vector<pair<int, int> > adj[n];
    long long totalSum = 0;
    
    for(int i = 0; i < n; ++i)
        totalSum += A[i];

    for(int i = 0; i < B.size(); ++i)
    {
        B[i][0]--;
        B[i][1]--;
    }
    
    for(auto e : B)
    {
        adj[e[0]].push_back({e[1], A[e[1]]});
        adj[e[1]].push_back({e[0], A[e[0]]});
    }
    
    t = 1;
    vector<int> vis(n, 0);
    vector<long long> sum(n, 0);
    dfs(0, adj, vis, sum, A);
    
    // mx = max(mx, (a*b)%mod)
    // ex. if we have 3 candidates {523, 175, 289} and MOD = 100
    // then ans = 289 (max(523 % 100, 175 % 100, 289 % 100)) :(
    // I know its frustrating when u dont get it first time
    
    long long ans = 0;
    for(auto e : B)
    {
        if(vis[e[0]] < vis[e[1]]) // checking who is parent
            ans = max(ans, ((totalSum-sum[e[1]]) * sum[e[1]]) % MOD);
        else
            ans = max(ans, ((totalSum-sum[e[0]]) * sum[e[0]]) % MOD);
    }
    return ans;
}
