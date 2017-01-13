#include <iostream>
#include <cmath>
#include <ctime>
#include "MyUtil.h"
#include "MyAlgorithmTester.h"

using namespace std;

int main() {

    // 数据规模倍乘测试findMax
    // O(n)
    cout<<"Test for findMax:"<<endl;
    for( int i = 10 ; i <= 26 ; i ++ ){

        int n = pow(2,i);
        int *arr = MyUtil::generateRandomArray(n, 0, 100000000);

        clock_t startTime = clock();
        MyAlgorithmTester::findMax(arr, n);
        clock_t endTime = clock();

        cout<<"data size 2^"<<i<<" = "<<n<<"\t";
        cout<<"Time cost: "<<double(endTime - startTime)/CLOCKS_PER_SEC<<endl;

        delete[] arr;
    }

    return 0;
}