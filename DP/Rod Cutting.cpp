// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/rod-cutting/
// Good question

/*
There is a rod of length N lying on x-axis with its left end at x = 0 and right end at x = N. Now, there are M weak points on this rod denoted by positive 
integer values(all less than N) A1, A2, …, AM. You have to cut rod at all these weak points. You can perform these cuts in any order. After a cut, rod gets
divided into two smaller sub-rods. Cost of making a cut is the length of the sub-rod in which you are making a cut.

Your aim is to minimise this cost. Return an array denoting the sequence in which you will make cuts. If two different sequences of cuts give same cost, 
return the lexicographically smallest.

Notes:
    Sequence a1, a2 ,…, an is lexicographically smaller than b1, b2 ,…, bm, if and only if at the first i where ai and bi differ, ai < bi, or if no such i found, 
	then n < m.
    N can be upto 109.

For example,
N = 6
A = [1, 2, 5]

If we make cuts in order [1, 2, 5], let us see what total cost would be.
For first cut, the length of rod is 6.
For second cut, the length of sub-rod in which we are making cut is 5(since we already have made a cut at 1).
For third cut, the length of sub-rod in which we are making cut is 4(since we already have made a cut at 2).
So, total cost is 6 + 5 + 4.

Cut order          | Sum of cost
(lexicographically | of each cut
 sorted)           |
___________________|_______________
[1, 2, 5]          | 6 + 5 + 4 = 15
[1, 5, 2]          | 6 + 5 + 4 = 15
[2, 1, 5]          | 6 + 2 + 4 = 12
[2, 5, 1]          | 6 + 4 + 2 = 12
[5, 1, 2]          | 6 + 5 + 4 = 15
[5, 2, 1]          | 6 + 5 + 2 = 13

So, we return [2, 1, 5].
*/

#define ll long long

vector<vector<ll> > dp;
vector<vector<int> > path;

ll rec(int i, int j, vector<int> &cuts)
{
    if(j-i <= 1)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    ll ans = LLONG_MAX;
    for(int k = i+1; k < j; ++k)
    {
        ll tempAns = rec(i, k, cuts) + rec(k, j, cuts) + cuts[j]-cuts[i];
        if(ans > tempAns)
        {
            ans = tempAns;
            path[i][j] = k;
        }
    }
    return dp[i][j] = ans;
}

void getPath(vector<int> &minPath, int i, int j, vector<int> &cuts)
{
    if(j-i <= 1)
        return;
    
    minPath.push_back(cuts[path[i][j]]);
    getPath(minPath, i, path[i][j], cuts);
    getPath(minPath, path[i][j], j, cuts);
}

vector<int> Solution::rodCut(int n, vector<int> &cuts)
{
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    
    dp = vector<vector<ll> >(cuts.size(), vector<ll>(cuts.size(), -1));
    path = vector<vector<int> >(cuts.size(), vector<int>(cuts.size()));
    
    int minCost = rec(0, cuts.size()-1, cuts);

    vector<int> minPath;
    getPath(minPath, 0, cuts.size()-1, cuts);
    return minPath;
}
