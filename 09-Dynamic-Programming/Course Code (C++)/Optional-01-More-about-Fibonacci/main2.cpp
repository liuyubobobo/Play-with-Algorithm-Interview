#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// 70. Climbing Stairs
/// https://leetcode.com/problems/climbing-stairs/description/
///
/// 斐波那契数可以根据一个特殊矩阵的幂的形式求出。
/// | F(n+1) F(n)   | = | 1 1 |^n
/// | F(n)   F(n-1) |   | 1 0 |
/// 幂运算可以使用分治法, 优化为O(logn)的复杂度
/// 具体该方法的证明, 有兴趣的同学可以自行在互联网上搜索学习。
///
/// 时间复杂度: O(logn)
/// 空间复杂度: O(1)
class Solution {

public:
    int climbStairs(int n) {

        assert(n > 0);

        if(n == 1)
            return 1;

        vector<vector<int>> base = {{1, 1}, {1, 0}};
        return matrix_pow(base, n)[0][0];
    }

private:
    vector<vector<int>> matrix_pow(const vector<vector<int>>& m, int n){

        if(n == 1)
            return m;

        vector<vector<int>> t = matrix_pow(m, n / 2);
        vector<vector<int>> res = matrix_multiply(t, t);
        if(n % 2)
            return matrix_multiply(res, m);
        return res;
    }

    vector<vector<int>> matrix_multiply(const vector<vector<int>>& m1,
                                        const vector<vector<int>>& m2){
        vector<vector<int>> res(2, vector<int>(2, 0));
        res[0][0] = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
        res[0][1] = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
        res[1][0] = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
        res[1][1] = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];
        return res;
    }
};

int main() {

    cout << Solution().climbStairs(10) << endl;
    return 0;
}