// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/order-of-people-heights/
// Good question, but dont know why this is question of trees
// Ref : https://www.youtube.com/watch?v=HKHkzKvb0J4&t=593s

vector<int> Solution::order(vector<int> &heights, vector<int> &infronts)
{
    vector<int> ans;
    vector<pair<int,int>> vp;
    
    for(int i = 0; i < heights.size(); i++)
        vp.push_back(make_pair(heights[i],infronts[i]));
    
    sort(vp.rbegin(),vp.rend());
    
    for(int i = 0; i < vp.size(); i++)
        ans.insert(ans.begin() + vp[i].second, vp[i].first);
    
    return ans;
}
