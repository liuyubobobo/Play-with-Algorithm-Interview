#include <iostream>
#include <cmath>
#include "MyUtil.h"
#include "MyAlgorithmTester.h"

using namespace std;

int main() {

    // 数据规模倍乘测试selectionSort
    // O(n^2)
    cout<<"Test for selectionSort:"<<endl;
    for( int i = 10 ; i <= 15 ; i ++ ){

        int n = pow(2,i);
        int *arr = MyUtil::generateRandomArray(n, 0, 100000000);

        clock_t startTime = clock();
        MyAlgorithmTester::selectionSort(arr,n);
        clock_t endTime = clock();

        cout<<"data size 2^"<<i<<" = "<<n<<"\t";
        cout<<"Time cost: "<<double(endTime - startTime)/CLOCKS_PER_SEC<<endl;

        delete[] arr;
    }

    return 0;
}