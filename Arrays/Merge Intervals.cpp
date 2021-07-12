// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/merge-intervals/
// Decent

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

*** IMP : You may assume that the intervals were initially sorted according to their start times***

Example 1:
Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
Make sure the returned intervals are also sorted.
*/

// App 1 : Simple
// TC : O(N logN)
// SC : O(N)

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval)
{
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), [](Interval& i1, Interval& i2){
        return i1.start < i2.start;
    });
    
    // now question remains normal merge overlapping intervals
    vector<Interval> v;
    int last = 0, end = intervals[0].end;
    for(int i = 1; i < intervals.size(); ++i)
    {
        if(intervals[i].start > end)
        {
            v.push_back(Interval(intervals[last].start, end));
            
            last = i;
            end = intervals[i].end;
        }
        else
        {
            end = max(end, intervals[i].end);
        }
    }
    v.push_back(Interval(intervals[last].start, end));
    return v;
}

// Smart Approach
// TC : O(N)
// SC : O(N)

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval)
{
    vector<Interval> ans = {newInterval};
    
    for(auto in : intervals)
    {
        auto top = ans.back();
        ans.pop_back();
        
        if(top.start > in.end)
        {
            ans.push_back(in);
            ans.push_back(top);
        }
        else if(in.start > top.end)
        {
            ans.push_back(top);
            ans.push_back(in);
        }
        else
        {
            ans.push_back(Interval(min(top.start, in.start), max(top.end, in.end)));
        }
    }
    return ans;
}
