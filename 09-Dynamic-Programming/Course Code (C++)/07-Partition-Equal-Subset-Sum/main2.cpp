#include <iostream>
#include <vector>
using namespace std;

class Solution {

public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for( int i = 0 ; i < nums.size() ; i ++ )
            sum += nums[i];

        if( sum%2 )
            return false;

        int n = nums.size();
        int W = sum/2;
        vector<bool> memo(W+1,false);
        for( int i = 0 ; i <= W ; i ++ )
            memo[i] = ( nums[0] == i );

        for( int i = 1 ; i < n ; i ++ )
            for( int j = W ; j >= nums[i] ; j -- )
                memo[j] = memo[j] || memo[j-nums[i]];

        return memo[W];
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