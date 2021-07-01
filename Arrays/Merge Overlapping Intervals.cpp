// By Vishwam Shriram Mundada
// https://www.interviewbit.com/old/problems/merge-overlapping-intervals/
// Easy

/*
Given a collection of intervals, merge all overlapping intervals.

For example:
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

vector<Interval> Solution::merge(vector<Interval> &A)
{
    vector<Interval> ans;
    sort(A.begin(), A.end(), [](Interval &a, Interval &b){
        return a.start < b.start;
    });
    
    int st = A[0].start;
    int en = A[0].end;
    for(int i = 1; i < A.size(); ++i)
    {
        if(A[i].start > en)
        {
            ans.push_back(Interval(st, en));
            st = A[i].start;
            en = A[i].end;
        }
        else
        {
            en = max(en, A[i].end);
        }
    }
    
    Interval temp = {st, en};
    ans.push_back(temp);

    return ans;
}
