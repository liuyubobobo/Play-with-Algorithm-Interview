#include <iostream>
#include <vector>

using namespace std;

// 改变状态定义
class Solution {
private:
    // memo[i] 表示考虑抢劫 nums[0...i] 所能获得的最大收益
    vector<int> memo;

    // 考虑抢劫nums[0...index]这个范围的所有房子
    int tryRob( vector<int> &nums, int index){

        if( index < 0 )
            return 0;

        if( memo[index] != -1 )
            return memo[index];

        int res = 0;
        for( int i = 0 ; i <= index ; i ++ )
            res = max(res, nums[i] + tryRob(nums, i-2));
        memo[index] = res;
        return res;
    }
public:
    int rob(vector<int>& nums) {

        memo = vector<int>(nums.size(), -1);
        return tryRob(nums, nums.size() - 1 );
    }
};

int main() {

    return 0;
}