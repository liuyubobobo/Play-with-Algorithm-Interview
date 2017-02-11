#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 另外一个滑动窗口的实现, 仅供参考
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        assert( s > 0 );

        int l = 0 , r = -1; // [l...r]为我们的窗口
        int sum = 0;
        int res = nums.size()+1;

        while( r + 1 < nums.size() ){   // 窗口的右边界无法继续扩展了, 则循环继续

            while( r + 1 < nums.size() && sum < s )
                sum += nums[++r];

            if( sum >= s )
                res = min(res, r-l+1);

            while( l < nums.size() && sum >= s ){
                sum -= nums[l++];
                if( sum >= s )
                    res = min(res, r-l+1);
            }
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