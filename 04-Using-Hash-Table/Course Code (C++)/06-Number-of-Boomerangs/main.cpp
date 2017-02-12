#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <stdexcept>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {

        int res = 0;
        for( int i = 0 ; i < points.size() ; i ++ ){

            unordered_map<int, int> record;
            for( int j = 0 ; j < points.size() ; j ++ )
                record[dis(points[i], points[j])] += 1;

            for( unordered_map<int, int>::iterator iter = record.begin() ; iter != record.end() ; iter ++ )
                res += (iter->second)*(iter->second-1);
        }
        return res;
    }

private:
    int dis( const pair<int,int> &pa, const pair<int,int> &pb){
        return (pa.first - pb.first) * (pa.first - pb.first) +
               (pa.second - pb.second) * (pa.second - pb.second);
    }
};

int main() {

    vector<pair<int,int>> vec;
    vec.push_back( make_pair(0, 0) );
    vec.push_back( make_pair(1, 0) );
    vec.push_back( make_pair(2, 0) );

    cout<<Solution().numberOfBoomerangs( vec )<<endl;

    return 0;
}