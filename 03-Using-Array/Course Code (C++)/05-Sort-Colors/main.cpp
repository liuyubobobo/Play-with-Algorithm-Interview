#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 时间复杂度: O(n)
// 空间复杂度: O(k), k为元素的取值范围
// 对整个数组遍历了两遍
class Solution {
public:
    void sortColors(vector<int> &nums) {

        int count[3] = {0};    // 存放0,1,2三个元素的频率
        for( int i = 0 ; i < nums.size() ; i ++ ){
            assert( nums[i] >= 0 && nums[i] <= 2 );
            count[nums[i]] ++;
        }

        int index = 0;
        for( int i = 0 ; i < count[0] ; i ++ )
            nums[index++] = 0;
        for( int i = 0 ; i < count[1] ; i ++ )
            nums[index++] = 1;
        for( int i = 0 ; i < count[2] ; i ++ )
            nums[index++] = 2;

        // 小练习: 更加自使用的计数排序
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
