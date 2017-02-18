#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        if( k == 0 )
            return vector<int>();

        unordered_map<int,int> freq;
        for(int i = 0 ; i < nums.size() ; i ++ )
            freq[nums[i]] ++;

        assert( k >= 0 && k <= freq.size() );

        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        for( unordered_map<int,int>::iterator iter = freq.begin() ;
             iter != freq.end() ; iter ++ ){
            if( pq.size() == k ){
                if( iter->second > pq.top().first ){
                    pq.pop();
                    pq.push( make_pair( iter->second , iter->first) );
                }
            }
            else
                pq.push( make_pair( iter->second , iter->first ) );
        }

        vector<int> res;
        while( !pq.empty() ){
            res.push_back( pq.top().second );
            pq.pop();
        }

        return res;
    }
};

int main() {

    int nums[] = {1, 1, 1, 2, 2, 3};
    vector<int> vec( nums, nums + sizeof(nums)/sizeof(int));
    int k = 2;

    vector<int> res = Solution().topKFrequent(vec, 2);
    for( int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}