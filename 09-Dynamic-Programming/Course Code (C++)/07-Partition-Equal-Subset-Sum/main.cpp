#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> memo;

    bool tryPartition(const vector<int> &nums, int index, int sum){

        if( sum == 0 )
            return true;

        if( sum < 0 || index < 0 )
            return false;

        if( memo[index][sum] != -1 )
            return memo[index][sum] == 1;

        memo[index][sum] = (tryPartition(nums, index-1 , sum ) ||
               tryPartition(nums, index-1 , sum - nums[index] ) ) ? 1 : 0;

        return memo[index][sum] == 1;
    }
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for( int i = 0 ; i < nums.size() ; i ++ )
            sum += nums[i];

        if( sum%2 )
            return false;

        memo = vector<vector<int>>(nums.size(), vector<int>(sum/2+1,-1));
        return tryPartition(nums, nums.size()-1 , sum/2 );
    }
};

int main() {

    int nums1[] = {1, 5, 11, 5};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));
    if( Solution().canPartition(vec1) )
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    int nums2[] = {1, 2, 3, 5};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));
    if( Solution().canPartition(vec2) )
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    return 0;
}