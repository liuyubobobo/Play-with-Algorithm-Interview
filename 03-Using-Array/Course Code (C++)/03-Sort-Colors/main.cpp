#include <iostream>
#include <vector>

using namespace std;

// 时间复杂度: O(n)
// 空间复杂度: O(k), k为元素的取值范围
class Solution {
public:
    void sortColors(vector<int> &A) {

        int count[3] = {0, 0, 0};    // 存放0,1,2三个元素的频率
        for( int i = 0 ; i < A.size() ; i ++ )
            count[A[i]] ++;

        for( int i = 1 ; i < 3 ; i ++ )
            count[i] += count[i-1];

        for( int i = 0 ; i < count[0] ; i ++ )
            A[i] = 0;
        for( int i = count[0] ; i < count[1] ; i ++ )
            A[i] = 1;
        for( int i = count[1] ; i < count[2] ; i ++ )
            A[i] = 2;

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
