#include <iostream>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        if( nums.size() <= 1 )
            return false;

        if( k <= 0 )
            return false;

        unordered_set<int> record;
        for( int i = 0 ; i < nums.size() ; i ++ ){
            // record中最多包含从 a 到 a + k 共 k + 1个元素
            if( record.size() >= k + 1 )
                record.erase(nums[i-k-1]);

            if( record.find( nums[i] ) != record.end() )
                return true;
            else
                record.insert( nums[i] );
        }


        return false;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}