#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


// 时间复杂度: O(n)
// 空间复杂度: O(1)
// 对整个数组只遍历了一遍
class Solution {
public:
    void sortColors(vector<int> &nums) {

        int zero = -1;          // [0...zero] == 0
        int two = nums.size();  // [two...n-1] == 2
        for( int i = 0 ; i < two ; ){
            if( nums[i] == 1 )
                i ++;
            else if ( nums[i] == 2 )
                swap( nums[i] , nums[--two]);
            else{ // nums[i] == 0
                assert( nums[i] == 0 );
                swap( nums[++zero] , nums[i++] );
            }
        }
    }
};

int main() {

    int nums[] = {2, 2, 2, 1, 1, 0};
    vector<int> vec = vector<int>( nums , nums + sizeof(nums)/sizeof(int));

    Solution().sortColors( vec );
    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;

    return 0;
}
