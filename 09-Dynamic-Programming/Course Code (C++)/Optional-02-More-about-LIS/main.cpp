#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// 300. Longest Increasing Subsequence
/// https://leetcode.com/problems/longest-increasing-subsequence/description/
///
/// 我们这一章介绍的动态规划法求解LIS问题, 时间复杂度为O(nlogn)的
/// LIS有一个经典的, 同时也非常巧妙的动态规划方法, 其时间复杂度为O(nlogn)的
/// 以下为参考代码和简单注释, 如果需要更详细的解释, 大家可以自行在互联网上搜索学习
/// 通过这个例子, 也请大家再体会改变动态规划的状态定义,
/// 带来解决问题方法的重大不同, 甚至是时间复杂度数量级上的巨大优化
///
/// 时间复杂度: O(nlogn)
/// 空间复杂度: O(n)
class Solution {

public:
    int lengthOfLIS(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        // dp[i] 表示最长长度为i的递增子序列, 最后一个数字的最小值
        vector<int> dp(nums.size() + 1, INT_MIN);
        dp[1] = nums[0];
        int len = 1;
        for(int i = 1 ; i < nums.size() ; i ++) {
            if(nums[i] > dp[len]){
                len ++;
                dp[len] = nums[i];
            }
            else{
                // 我们的dp数组将是一个单调递增的数组, 所以可以使用二分查找法
                vector<int>::iterator iter = lower_bound(dp.begin(), dp.begin() + (len + 1), nums[i]);
                if(*iter != nums[i]){
                    int index = iter - dp.begin();
                    assert(index >= 1 && index <= len);
                    dp[index] = min(dp[index], nums[i]);
                }
            }
        }

        return len;
    }
};

int main() {

    int nums1[] = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));
    cout << Solution().lengthOfLIS(vec1) << endl;
    // 4

    // ---

    int nums2[] = {4, 10, 4, 3, 8, 9};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));
    cout << Solution().lengthOfLIS(vec2) << endl;
    // 3

    // ---

    int nums3[] = {2, 2};
    vector<int> vec3(nums3, nums3 + sizeof(nums3)/sizeof(int));
    cout << Solution().lengthOfLIS(vec3) << endl;
    // 1

    // ---

    int nums4[] = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    vector<int> vec4(nums4, nums4 + sizeof(nums4)/sizeof(int));
    cout << Solution().lengthOfLIS(vec4) << endl;
    // 6

    return 0;
}