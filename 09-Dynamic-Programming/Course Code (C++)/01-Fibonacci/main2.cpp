#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

vector<int> memo;
int num = 0;

// 记忆化搜索
int fib(int n){

    num ++;

    if(n == 0)
        return 0;

    if(n == 1)
        return 1;

    if(memo[n] == -1)
        memo[n] = fib(n - 1) + fib(n - 2);

    return memo[n];
}

int main() {

    num = 0;

    //int n = 42;
    int n = 1000; // 注意: 我们使用n = 1000只是为了测试性能, 实际上会溢出
                  // 斐波那契额数列是以指数速度上涨的
    memo = vector<int>(n + 1, -1);

    time_t startTime = clock();
    int res = fib(n);
    time_t endTime = clock();

    cout << "fib(" << n << ") = " << res << endl;
    cout << "time : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    cout << "run function fib() " << num << "times." << endl;

    return 0;
}