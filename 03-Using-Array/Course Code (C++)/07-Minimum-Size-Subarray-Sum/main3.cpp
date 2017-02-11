#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 滑动窗口的思路
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int l = 0 , r = -1; // nums[l...r]为我们的滑动窗口
        int sum = 0;
        int res = nums.size()+1;

        while( l < nums.size() ){   // 窗口的左边界在数组范围内,则循环继续

            if( r + 1 < nums.size() && sum < s )
                sum += nums[++r];
            else // r已经到头 或者 sum >= s
                sum -= nums[l++];

            if( sum >= s )
                res = min(res, r-l+1);
        }

        if( res == nums.size() + 1 )
            return 0;
        return res;
    }
};

int main() {

    int nums[] = {2, 3, 1, 2, 4, 3};
    vector<int> vec( nums, nums + sizeof(nums)/sizeof(int) );
    int s = 7;

    cout<<Solution().minSubArrayLen(s, vec)<<endl;

    return 0;
}