#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

vector<int> memo;

// 记忆化搜索
int fib( int n ){

    if( n == 0 )
        return 0;

    if( n == 1 )
        return 1;

    if( memo[n] == -1 )
        memo[n] = fib(n-1) + fib(n-2);

    return memo[n];
}

int main() {

    int n = 1000;
    memo = vector<int>(n+1,-1);

    time_t startTime = clock();
    int res = fib(n);
    time_t endTime = clock();

    cout<<"fib("<<n<<") = "<<res<<endl;
    cout<<"time : "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;

    return 0;
}