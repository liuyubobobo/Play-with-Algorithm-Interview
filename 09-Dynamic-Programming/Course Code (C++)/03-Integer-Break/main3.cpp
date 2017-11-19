#include <iostream>
#include <vector>

using namespace std;

/// 343. Integer Break
/// https://leetcode.com/problems/integer-break/description/
/// 动态规划
/// 时间复杂度: O(n^2)
/// 空间复杂度: O(n)
class Solution {

private:
    int max3(int a, int b, int c ){
        return max(max(a, b), c);
    }

public:
    int integerBreak(int n) {

        assert(n >= 1);

        // memo[i] 表示将数字i分割(至少分割成两部分)后得到的最大乘积
        vector<int> memo(n + 1, -1);

        memo[1] = 1;
        for(int i = 2 ; i <= n ; i ++)
            // 求解memo[i]
            for(int j = 1 ; j <= i - 1 ; j ++)
                memo[i] = max3(memo[i], j * (i - j), j * memo[i - j]);

        return memo[n];
    }
};

int main() {

    cout << Solution().integerBreak(2) << endl;
    cout << Solution().integerBreak(3) << endl;
    cout << Solution().integerBreak(4) << endl;
    cout << Solution().integerBreak(10) << endl;

    return 0;
}