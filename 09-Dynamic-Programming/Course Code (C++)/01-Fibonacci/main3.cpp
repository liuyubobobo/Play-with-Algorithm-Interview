#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

// 动态规划
int fib( int n ){

    vector<int> memo(n + 1, -1);

    memo[0] = 0;
    memo[1] = 1;
    for(int i = 2 ; i <= n ; i ++)
        memo[i] = memo[i - 1] + memo[i - 2];

    return memo[n];
}

int main() {

    // int n = 42
    int n = 1000; // 注意: 我们使用n = 1000只是为了测试性能, 实际上会溢出
                  // 斐波那契额数列是以指数速度上涨的

    time_t startTime = clock();
    int res = fib(n);
    time_t endTime = clock();

    cout << "fib(" << n << ") = " << res << endl;
    cout << "time : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

    return 0;
}