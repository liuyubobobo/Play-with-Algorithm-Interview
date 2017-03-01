#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 一个错误的思路
class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> res;
        if( n == 0 )
            return res;

        if( n == 1 ){
            res.push_back("()");
            return res;
        }

        vector<string> tmp = generateParenthesis(n-1);
        for( int i = 0 ; i < tmp.size() ; i ++ ){
            res.push_back( "()" + tmp[i] );
            res.push_back( "(" + tmp[i] + ")" );
            res.push_back( tmp[i] + "()" );
        }

        return res;
    }
};

int main() {

    vector<string> res = Solution().generateParenthesis(3);
    for( int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<endl;

    return 0;
}