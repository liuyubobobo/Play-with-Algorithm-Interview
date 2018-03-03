#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

// 1. Two Sum
// https://leetcode.com/problems/two-sum/description/
//
// 感谢课程中的 @Charles_Zhang 提出:
// 由于题目中只要求求出唯一的一个解。因此可以在最初的时候遍历整个数组, 将数组中的每个数字的索引放在map中。
// 此时, record中记录的永远是每一个数字最后出现的位置。
// 而对于 target = 2*a的情况, 如果nums中有两个或两个以上a,
// 我们在扫描时会先看到第一个a, 而从record中拿到的是最后一个a :)
//
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> record;
        for(int i = 0 ; i < nums.size() ; i ++)
            record[nums[i]] = i;

        for(int i = 0 ; i < nums.size() ; i ++){

            if(record.find(target - nums[i]) != record.end())
                if(record[target - nums[i]] != i)
                    return {i, record[target - nums[i]]};

            record[nums[i]] = i;
        }

        throw invalid_argument("the input has no solution");
    }
};


int main() {

    const int nums[] = {0,4,3,0};
    vector<int> nums_vec( nums, nums + sizeof(nums)/sizeof(int) );
    int target = 0;

    vector<int> res = Solution().twoSum(nums_vec, target);
    cout << res[0] << " " << res[1] << endl;

    return 0;
}