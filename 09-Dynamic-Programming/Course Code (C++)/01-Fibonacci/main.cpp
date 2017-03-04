#include <iostream>
#include <ctime>

using namespace std;

int fib( int n ){

    if( n == 0 )
        return 0;

    if( n == 1 )
        return 1;

    return fib(n-1) + fib(n-2);
}

int main() {

    int n = 42;
    time_t startTime = clock();
    int res = fib(n);
    time_t endTime = clock();
    cout<<"fib("<<n<<") = "<<res<<endl;
    cout<<"time : "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;

    return 0;
}