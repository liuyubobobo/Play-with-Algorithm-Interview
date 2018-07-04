#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

/// LCS问题
/// 动态规划
/// 时间复杂度: O(len(s1)*len(s2))
/// 空间复杂度: O(len(s1)*len(s2))
class LCS{

public:
    string getLCS(const string &s1, const string &s2){

        int m = s1.size();
        int n = s2.size();

        // 对memo的第0行和第0列进行初始化
        vector<vector<int> > memo(m, vector<int>(n, 0));
        for(int j = 0 ; j < n ; j ++)
            if(s1[0] == s2[j]){
                for(int k = j ; k < n ; k ++)
                    memo[0][k] = 1;
                break;
            }

        for(int i = 0 ; i < m ; i ++)
            if(s1[i] == s2[0]){
                for(int k = i ; k < m ; k ++)
                    memo[k][0] = 1;
                break;
            }

        // 动态规划的过程
        for(int i = 1 ; i < m ; i ++)
            for(int j = 1 ; j < n ; j ++)
                if(s1[i] == s2[j])
                    memo[i][j] = 1 + memo[i-1][j-1];
                else
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);

        // 通过memo反向求解s1和s2的最长公共子序列
        m = s1.size() - 1;
        n = s2.size() - 1;
        string res = "";
        while(m >= 0 && n >= 0)
            if( s1[m] == s2[n] ){
                res = s1[m] + res;
                m --;
                n --;
            }
            else if(m == 0)
                n --;
            else if(n == 0)
                m --;
            else{
                if(memo[m-1][n] > memo[m][n-1])
                    m --;
                else
                    n --;
            }

        return res;
    }
};

int main() {

    string s1, s2;
    cin >> s1 >> s2;
    cout << LCS().getLCS(s1, s2) << endl;

    return 0;
}