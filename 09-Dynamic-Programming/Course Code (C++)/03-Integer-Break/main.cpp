#include <iostream>

using namespace std;

class Solution {
private:
    int breakInteger( int n ){

        int res = n;
        for( int i = 1 ; i <= n-1 ; i ++ )
            res = max( res , i * breakInteger(n-i) );
        return res;
    }
public:
    int integerBreak(int n) {

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