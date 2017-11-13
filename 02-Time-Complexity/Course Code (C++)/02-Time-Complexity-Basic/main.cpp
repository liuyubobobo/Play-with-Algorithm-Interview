#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main() {

    // 数据规模每次增大10倍进行测试
    // 有兴趣的同学也可以试验一下数据规模每次增大2倍哦:)
    for( int x = 1 ; x <= 9 ; x ++ ){

        int n = pow(10, x);

        clock_t startTime = clock();

        long long sum = 0;
        for( int i = 0 ; i < n ; i ++ )
            sum += i;
        clock_t endTime = clock();

        cout << "sum = " << sum << endl;
        cout << "10^" << x << " : "
             << double(endTime - startTime)/CLOCKS_PER_SEC
             << " s" << endl << endl;
    }
    return 0;
}