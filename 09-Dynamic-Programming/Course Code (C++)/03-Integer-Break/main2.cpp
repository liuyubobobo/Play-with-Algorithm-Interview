#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> memo;

    int max3( int a , int b , int c ){
        return max( a , max(b,c) );
    }

    // 将n进行分割(至少分割两部分), 可以获得的最大乘积
    int breakInteger( int n ){

        if( n == 1 )
            return 1;

        if( memo[n] != -1 )
            return memo[n];

        int res = -1;
        for( int i = 1 ; i <= n-1 ; i ++ )
            res = max3( res , i*(n-i) , i * breakInteger(n-i) );
        memo[n] = res;
        return res;
    }
public:
    int integerBreak(int n) {
        assert( n >= 1 );
        memo = vector<int>(n+1, -1);
        return breakInteger(n);
    }
};

int main() {

    cout<<Solution().integerBreak(2)<<endl;
    cout<<Solution().integerBreak(10)<<endl;
    return 0;
}