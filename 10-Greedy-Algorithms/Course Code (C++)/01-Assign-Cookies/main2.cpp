#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// 455. Assign Cookies
/// https://leetcode.com/problems/assign-cookies/description/
/// 先尝试满足最不贪心的小朋友
/// 时间复杂度: O(nlogn)
/// 空间复杂度: O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int gi = 0, si = 0;
        int res = 0;
        while(gi < g.size() && si < s.size()){
            if(s[si] >= g[gi]){
                res ++;
                si ++;
                gi ++;
            }
            else
                si ++;
        }

        return res;
    }
};

int main() {

    int g1[] = {1, 2, 3};
    vector<int> gv1(g1, g1 + sizeof(g1)/sizeof(int));
    int s1[] = {1, 1};
    vector<int> sv1(s1, s1 + sizeof(s1)/sizeof(int));
    cout << Solution().findContentChildren(gv1, sv1) << endl;

    int g2[] = {1, 2};
    vector<int> gv2(g2, g2 + sizeof(g2)/sizeof(int));
    int s2[] = {1, 2, 3};
    vector<int> sv2(s2, s2 + sizeof(s2)/sizeof(int));
    cout << Solution().findContentChildren(gv2, sv2) << endl;

    return 0;
}