#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 时间复杂度O(n^2)
// 空间复杂度O(1) 不需要额外开空间
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size(); // n为triangle的行数
        if( n == 0 )
            return 0;

        // 让triangle[i][j]存储到达(i,j)这个位置的最小值
        // triangle[0][0]不用处理
        for( int i = 1 ; i < triangle.size() ; i ++ ){
            int m = triangle[i].size(); // m为triangle第i行的列数

            // 确保传入的triangle合法
            // 第0行有1个元素; 第1行有2个元素; 第2行有3个元素...
            // 第i行有i+1个元素
            assert( m == i + 1 );

            // 每一行第0个元素只能从上一行第0个元素过来
            triangle[i][0] += triangle[i-1][0];

            // 每一行最后一个元素只能从上一行最后一个元素过来
            // 如果这一行最后一个元素是(i,m-1), 上一行最后一个元素师(i-1,m-2)
            triangle[i][m-1] += triangle[i-1][m-2];

            // 每一行的其他元素(i,j)可以从上一行的(i-1,j-1)和(i-1,j)两个方向过来
            for( int j = 1 ; j < m-1 ; j ++ )
                triangle[i][j] += min( triangle[i-1][j-1], triangle[i-1][j] );
        }

        // 扫描此时triangle的最后一行,最小值即为答案
        int res = triangle[n-1][0];
        for( int j = 1 ; j < triangle[n-1].size() ; j ++ )
            res = min( res , triangle[n-1][j] );
        return res;
    }
};

int main() {

    return 0;
}