#include <iostream>
#include <vector>

using namespace std;


/// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(const Interval &a, const Interval &b){
    return a.start < b.start;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(), compare);

        int res = 0, pre = 0;
        for( int i = 1 ; i < intervals.size() ; i ++ )
            if( intervals[i].start >= intervals[pre].end )
                pre = i;
            else{
                res ++;
                if( intervals[i].end < intervals[pre].end )
                    pre = i;
            }

        return res;
    }
};

int main() {

    Interval interval1[] = {Interval(1,2), Interval(2,3), Interval(3,4), Interval(1,3)};
    vector<Interval> v1( interval1, interval1 + sizeof(interval1)/sizeof(Interval));
    cout<<Solution().eraseOverlapIntervals(v1)<<endl;

    Interval interval2[] = {Interval(1,2), Interval(1,2), Interval(1,2)};
    vector<Interval> v2( interval2, interval2 + sizeof(interval2)/sizeof(Interval));
    cout<<Solution().eraseOverlapIntervals(v2)<<endl;

    Interval interval3[] = {Interval(1,2), Interval(2,3)};
    vector<Interval> v3( interval3, interval3 + sizeof(interval3)/sizeof(Interval));
    cout<<Solution().eraseOverlapIntervals(v3)<<endl;

    return 0;
}