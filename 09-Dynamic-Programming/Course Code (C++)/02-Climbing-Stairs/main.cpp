#include <iostream>
#include <vector>

using namespace std;

/// 70. Climbing Stairs
/// https://leetcode.com/problems/climbing-stairs/description/
/// 记忆化搜索
/// 时间复杂度: O(n)
/// 空间复杂度: O(n)
class Solution {

private:
    vector<int> memo;

    int calcWays(int n){

        if(n == 0 || n == 1)
            return 1;

        if(memo[n] == -1)
            memo[n] = calcWays(n - 1) + calcWays(n - 2);

        return memo[n];
    }

public:
    int climbStairs(int n) {

        memo = vector<int>(n + 1, -1);
        return calcWays(n);
    }
};

int main() {

    cout << Solution().climbStairs(10) << endl;

    return 0;
}