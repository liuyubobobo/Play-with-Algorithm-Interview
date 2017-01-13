#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include "util.h"

using namespace std;

template<typename T>
int binarySearch( T arr[], int n, T target ){

    int l = 0, r = n; // target在[l...r)的范围里
    while( l < r ){    // 当 l == r时,区间[l...r)是一个无小区间
        int mid = l + (r-l)/2;
        if( arr[mid] == target ) return mid;
        if( target > arr[mid] )
            l = mid + 1;    // target在[mid+1...r)中; [l...mid]一定没有target
        else// target < arr[mid]
            r = mid;        // target在[l...mid)中; [mid...r)一定没有target
    }

    return -1;
}

int main() {

    int n = pow(10,7);
    int* data = MyUtil::generateOrderedArray(n);

    clock_t startTime = clock();
    for( int i = 0 ; i < n ; i ++ )
        assert( i == binarySearch(data, n, i) );
    clock_t endTime = clock();

    cout<<"binarySearch2 test complete."<<endl;
    cout<<"Time cost: "<<double(endTime - startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}