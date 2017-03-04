#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> memo;

    int breakInteger( int n ){

        if( memo[n] != -1 )
            return memo[n];

        int res = n;
        for( int i = 1 ; i <= n-1 ; i ++ )
            res = max( res , i * breakInteger(n-i) );
        memo[n] = res;
        return res;
    }
public:
    int integerBreak(int n) {

        memo = vector<int>(n+1, -1);
        int res = -1;
        for( int i = 1 ; i <= n-1 ; i ++ )
            res = max( res , i * breakInteger(n-i) );
        return res;
    }
};

int main() {

    cout<<Solution().integerBreak(2)<<endl;
    cout<<Solution().integerBreak(10)<<endl;
    return 0;
}