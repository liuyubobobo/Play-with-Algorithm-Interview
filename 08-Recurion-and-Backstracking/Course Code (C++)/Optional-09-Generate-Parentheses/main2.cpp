#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> res;

    void generateParenthesisString(int l , int r , const string &s){

        if( l == 0 && r == 0 ){
            res.push_back( s );
            return;
        }

        if( l > 0 )
            generateParenthesisString( l - 1 , r , s + "(" );

        if( r > l )
            generateParenthesisString( l , r - 1 , s + ")" );
    }

public:
    vector<string> generateParenthesis(int n) {

        res.clear();

        if( n == 0 )
            return res;

        generateParenthesisString(n , n , "");

        return res;
    }
};

int main() {

    vector<string> res = Solution().generateParenthesis(3);
    for( int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<endl;

    return 0;
}