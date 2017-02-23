#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 使用visited数组,记录每一个入队元素
class Solution {
public:
    int numSquares(int n) {

        queue< pair<int,int> > q;
        q.push( make_pair( n , 0 ) );

        vector<bool> visited(n+1, false);
        visited[n] = true;

        while( !q.empty() ){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            if( num == 0 )
                return step;

            for( int i = 1 ; num - i*i >= 0 ; i ++ )
                if( !visited[num-i*i] ){
                    q.push( make_pair( num - i*i , step + 1 ) );
                    visited[num-i*i] = true;
                }
        }

        throw invalid_argument("No Solution.");
    }
};

int main() {

    cout<<Solution().numSquares(12)<<endl;
    cout<<Solution().numSquares(13)<<endl;

    return 0;
}