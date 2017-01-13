#include <iostream>

using namespace std;


// O(1)
void swapTwoInts( int &a , int &b ){
    int temp = a;
    a = b;
    b = temp;
    return;
}

// O(n) Time Complexity
int sum( int n ){

    int ret = 0;
    for( int i = 0 ; i <= n ; i ++ )
        ret += i;
    return ret;
}

void reverse( string &s ){

    int n = s.size();
    for( int i = 0 ; i < n/2 ; i ++ )
        swap( s[i] , s[n-1-i] );
    return;
}

// O(n^2) Time Complexity
void selectionSort(int arr[], int n){

    for(int i = 0 ; i < n ; i ++){
        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;

        swap( arr[i] , arr[minIndex] );
    }
}

// O(n) Time Complexity
void printInformation(int n){

    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= 30 ; j ++ )
            cout<<"Class "<<i<<" - "<<"No. "<<j<<endl;
    return;
}

// O(logn) Time Complexity
int binarySearch(int arr[], int n, int target){

    int l = 0, r = n-1;
    while( l <= r ){
        int mid = l + (r-l)/2;
        if( arr[mid] == target ) return mid;
        if( arr[mid] > target ) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

string intToString( int num ){

    string s = "";
    string sign = "+";
    if( num < 0 ){
        num = -num;
        sign = "-";
    }

    while( num ){
        s += '0' + num%10;
        num /= 10;
    }

    if( s == "" )
        s = "0";

    reverse(s);
    if( sign == "-" )
        return sign + s;
    else
        return s;
}


// O(nlogn)
void hello(int n){

    for( int sz = 1 ; sz < n ; sz += sz )
        for( int i = 1 ; i < n ; i ++ )
            cout<<"Hello, Algorithm!"<<endl;
}


// O(sqrt(n)) Time Complexity
bool isPrime( int num ){

    for( int x = 2 ; x*x <= num ; x ++ )
        if( num%x == 0 )
            return false;
    return true;
}

bool isPrime2( int num ){

    if( num <= 1 ) return false;
    if( num == 2 ) return true;
    if( num%2 == 0 ) return false;

    for( int x = 3 ; x*x <= num ; x += 2 )
        if( num%x == 0 )
            return false;

    return true;
}


int main() {

    cout << intToString(123)<<endl;
    cout << intToString(0)<<endl;
    cout << intToString(-123)<<endl;

    cout<<endl;

    if( isPrime2(137) ) cout<<"137 is a prime."<<endl;
    else cout<<"137 is not a prime."<<endl;

    if( isPrime2(121) ) cout<<"121 is a prime."<<endl;
    else cout<<"121 is not a prime."<<endl;

    return 0;
}