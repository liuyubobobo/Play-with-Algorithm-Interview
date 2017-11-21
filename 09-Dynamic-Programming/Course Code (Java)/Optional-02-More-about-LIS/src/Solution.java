import java.util.Arrays;

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
public class Solution {

    public int lengthOfLIS(int[] nums) {

        if(nums.length == 0)
            return 0;

        // dp[i] 表示最长长度为i的递增子序列, 最后一个数字的最小值
        int dp[] = new int[nums.length + 1];
        Arrays.fill(dp, Integer.MIN_VALUE);

        int len = 1;
        dp[1] = nums[0];
        for(int i = 1 ; i < nums.length ; i ++)
            if(nums[i] > dp[len]){
                len ++;
                dp[len] = nums[i];
            }
            else{
                // 我们的dp数组将是一个单调递增的数组, 所以可以使用二分查找法
                int index = lowerBound(dp, 0, len, nums[i]);
                if(dp[index] != nums[i])
                    dp[index] = Math.min(dp[index], nums[i]);
            }

        return len;
    }

    // lowerBound求出arr[l...r]范围里，大于等于target的第一个元素所在的索引
    private int lowerBound(int[] arr, int l, int r, int target){

        int left = l, right = r + 1;
        while(left != right){
            int mid = left + (right - left) / 2;
            if(arr[mid] >= target)
                right = mid;
            else // arr[mid] < target
                left = mid + 1;
        }
        return left;
    }

    public static void main(String[] args) {

        int nums1[] = {10, 9, 2, 5, 3, 7, 101, 18};
        System.out.println((new Solution()).lengthOfLIS(nums1));
        // 4

        // ---

        int nums2[] = {4, 10, 4, 3, 8, 9};
        System.out.println((new Solution()).lengthOfLIS(nums2));
        // 3

        // ---

        int nums3[] = {2, 2};
        System.out.println((new Solution()).lengthOfLIS(nums3));
        // 1

        // ---

        int nums4[] = {1, 3, 6, 7, 9, 4, 10, 5, 6};
        System.out.println((new Solution()).lengthOfLIS(nums4));
        // 6
    }
}
