#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

// 1. Two Sum
// https://leetcode.com/problems/two-sum/description/
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> record;
        for(int i = 0 ; i < nums.size() ; i ++){

            int complement = target - nums[i];
            if(record.find(complement) != record.end()){
                int res[] = {i, record[complement]};
                return vector<int>(res, res + 2);
            }

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