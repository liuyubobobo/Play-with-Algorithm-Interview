#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 279. Perfect Squares
// https://leetcode.com/problems/perfect-squares/description/
// 该方法会导致 Time Limit Exceeded 或者 Memory Limit Exceeded
//
// 时间复杂度: O(2^n)
// 空间复杂度: O(2^n)
class Solution {
public:
    int numSquares(int n) {

        queue<pair<int, int>> q;
        q.push(make_pair(n, 0));
        while(!q.empty()){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            if(num == 0)
                return step;

            for(int i = 1 ; num - i*i >= 0 ; i ++)
                q.push(make_pair(num - i * i, step + 1));
        }

        throw invalid_argument("No Solution.");
    }
};

int main() {

    cout << Solution().numSquares(12) << endl;
    cout << Solution().numSquares(13) << endl;

    return 0;
}