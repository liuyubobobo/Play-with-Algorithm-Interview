#include <iostream>
#include <cassert>

using namespace std;

class Solution {
private:
    int max3( int a , int b , int c ){
        return max( a , max(b,c) );
    }

    // 将n进行分割(至少分割两部分), 可以获得的最大乘积
    int breakInteger( int n ){

        if( n == 1 )
            return 1;

        int res = -1;
        for( int i = 1 ; i <= n-1 ; i ++ )
            res = max3( res , i*(n-i) , i * breakInteger(n-i) );
        return res;
    }
public:
    int integerBreak(int n) {
        assert( n >= 1 );
        return breakInteger(n);
    }
};

int main() {

    cout<<Solution().integerBreak(2)<<endl;
    cout<<Solution().integerBreak(10)<<endl;
    return 0;
}