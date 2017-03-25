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

    if( a.start != b.start )
        return a.start < b.start;
    return a.end < b.end;
}

// 动态规划
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {

        if( intervals.size() == 0 )
            return 0;

        sort(intervals.begin(), intervals.end(), compare);

        int res = 0;
        vector<int> memo( intervals.size() , 1 );
        for( int i = 1 ; i < intervals.size() ; i ++ )
            for( int j = 0 ; j < i ; j ++ )
                if( intervals[i].start >= intervals[j].end )
                    memo[i] = max( memo[i] , 1 + memo[j] );

        return intervals.size() - memo[intervals.size()-1];
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