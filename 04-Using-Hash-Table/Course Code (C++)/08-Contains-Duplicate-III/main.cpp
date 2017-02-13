#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <stdexcept>
#include <cmath>

using namespace std;

// 时间复杂度: O(nlogn)
// 空间复杂度: O(k)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        set<long long> record;
        for( int i = 0 ; i < nums.size() ; i ++ ){

            if( record.lower_bound( (long long)nums[i] - (long long)t ) != record.end() &&
                *record.lower_bound( (long long)nums[i] - (long long)t ) <= (long long)nums[i] + (long long)t )
                return true;

            record.insert( nums[i] );

            if( record.size() == k + 1 )
                record.erase( nums[i-k] );
        }

        return false;
    }
};

int main() {

    int nums[] = {-2147483648,-2147483647};
    vector<int> vec( nums, nums + sizeof(nums)/sizeof(int));
    int k = 3;
    int t = 3;

    if( Solution().containsNearbyAlmostDuplicate(vec, k, t) )
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    return 0;
}