#include <iostream>
#include <cassert>

using namespace std;

// binarySearch
int binarySearch(int arr[], int l, int r, int target){

    if( l > r )
        return -1;

    int mid = l + (r-l)/2;
    if( arr[mid] == target )
        return mid;
    else if( arr[mid] > target )
        return binarySearch(arr, l, mid-1, target);
    else
        return binarySearch(arr, mid+1, r, target);

}

// sum
int sum( int n ){

    assert( n >= 0 );

    if( n == 0 )
        return 0;
    return n + sum(n-1);
}

// pow2
double pow( double x, int n ){

    assert( n >= 0 );

    if( n == 0 )
        return 1.0;

    double t = pow(x, n/2);
    if( n%2 )
        return x*t*t;

    return t*t;
}

int main() {

    cout<<sum(100)<<endl;
    cout<<pow(2,10)<<endl;

    return 0;
}