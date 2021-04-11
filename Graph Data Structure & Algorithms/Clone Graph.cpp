// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/clone-graph/
// Good question

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) 
{
    queue<UndirectedGraphNode*> q;
    q.push(node);
    
    map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    mp[node] = new UndirectedGraphNode(node -> label);
    
    while(!q.empty())
    {
        UndirectedGraphNode* curr = q.front();
        q.pop();
        
        vector<UndirectedGraphNode*> v = curr -> neighbors;
        for(int i = 0; i < v.size(); ++i)
        {
            if(mp.find(v[i]) == mp.end())
            {
                UndirectedGraphNode* copy = new UndirectedGraphNode(v[i] -> label);
                mp[v[i]] = copy;
                q.push(v[i]);
            }
            mp[curr] -> neighbors.push_back(mp[v[i]]);
        }
    }
    return mp[node];
}
