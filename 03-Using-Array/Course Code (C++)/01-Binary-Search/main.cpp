#include <iostream>

using namespace std;

template<typename T>
int binarySearch( T arr[], int n, T target ){

    int l = 0, r = n-1; // target在[l...r]的范围里
    while( l <= r ){    // 当 l == r时,区间[l...r]依然是有效的
        int mid = l + (r-l)/2;
        if( arr[mid] == target ) return mid;
        if( target > arr[mid] )
            l = mid + 1;  // target在[mid+1...r]中; [l...mid]一定没有target
        else
            r = mid - 1;  // target在[mid+1...r]中; [l...mid]一定没有target
    }

    return -1;
}

int main() {

    return 0;
}