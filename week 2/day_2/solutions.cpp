/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compareTwoInterval(Interval a, Interval b)
{
    if (a.start != b.start)
        return a.start < b.start;
    else
        return a.end < b.end;
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval)
{

    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), compareTwoInterval);

    vector<Interval> ans;
    int x = intervals[0].start, y = intervals[0].end;

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i].start >= x && intervals[i].start <= y)
        {
            y = max(y, intervals[i].end);
        }
        else
        {
            ans.push_back({x, y});
            x = intervals[i].start;
            y = intervals[i].end;
        }
    }

    ans.push_back({x, y});
    return ans;
}

// add update