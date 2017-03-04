#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if( n == 0 )
            return 0;

        // memo[i] 表示抢劫 nums[i...n) 所能获得的最大收益
        vector<int> memo(n, 0);
        memo[n-1] = nums[n-1];
        for( int i = n-2 ; i >= 0 ; i -- ) {
            memo[i] = memo[i+1];
            for (int j = i; j < n; j++)
                memo[i] = max(memo[i], nums[j] + (j + 2 < n ? memo[j + 2] : 0) );
        }
        return memo[0];
    }
};

int main() {

    int nums[] = {2,1};
    vector<int> vec(nums, nums+sizeof(nums)/sizeof(int));

    cout<<Solution().rob(vec)<<endl;

    return 0;
}