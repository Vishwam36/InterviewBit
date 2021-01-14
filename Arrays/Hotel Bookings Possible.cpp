// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/hotel-bookings-possible/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) 
{
    int rooms = 0, n = arrive.size();
    vector<pair<int,int> > v;
    
    for(int i = 0; i < n; ++i)
    {
        v.push_back(make_pair(arrive[i],1));
        v.push_back(make_pair(depart[i],0));
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < 2*n; ++i)
    {
        if(v[i].second == 1)
        {
            ++rooms;
        }
        else
        {
            --rooms;
        }
        if(rooms > K)
        {
            return false;
        }
    }
    return true;
}
