/// Source : https://leetcode.com/problems/climbing-stairs/description/
/// Author : liuyubobobo
/// Time   : 2017-11-20

#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

/// 70. Climbing Stairs
/// https://leetcode.com/problems/climbing-stairs/description/
///
/// 对于第n个斐波那契数, 可以推导出其公式
/// Fn = 1/sqrt(5) * {[(1+sqrt(5))/2]^n - [(1-sqrt(5))/2]^n}
/// 具体推导过程, 有兴趣的同学可以自行在互联网上搜索学习。
/// 注意: 这个方法的时间复杂度依然是O(logn)的,因为数的幂运算也需要logn的时间
/// 但这个方法快于使用矩阵的幂运算符的方法
///
/// 时间复杂度: O(logn)
/// 空间复杂度: O(1)
class Solution {

public:
    int climbStairs(int n) {

        assert(n > 0);

        if(n == 1)
            return 1;

        double sqrt5 = sqrt(5.0);
        return (int)((pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1)) / sqrt5);
    }

};

int main() {

    cout << Solution().climbStairs(10) << endl;
    return 0;
}