#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Memory Limit Exceed
class Solution {
public:
    int numSquares(int n) {

        queue< pair<int,int> > q;
        q.push( make_pair( n , 0 ) );
        while( !q.empty() ){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            if( num == 0 )
                return step;

            for( int i = 1 ; num - i*i >= 0 ; i ++ )
                q.push( make_pair( num - i*i , step + 1 ) );
        }

        throw invalid_argument("No Solution.");
    }
};

int main() {

    cout<<Solution().numSquares(12)<<endl;
    cout<<Solution().numSquares(13)<<endl;

    return 0;
}