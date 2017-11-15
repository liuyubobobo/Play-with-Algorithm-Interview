#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//
// 滑动窗口
// 其中使用last[c]保存字符c上一次出现的位置, 用于在右边界发现重复字符时, 快速移动左边界
// 使用这种方法, 时间复杂度依然为O(n), 但是只需要动r指针, 实际上对整个s只遍历了一次
// 相较而言, 之前的方法, 需要移动l和r两个指针, 相对于对s遍历了两次
//
// 时间复杂度: O(len(s))
// 空间复杂度: O(len(charset))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int last[256];
        memset(last, -1, sizeof(last));

        int l = 0, r = -1; //滑动窗口为s[l...r]
        int res = 0;
        while(r + 1 < s.size()){

            r ++;
            if(last[s[r]] != -1)
                l = max(l, last[s[r]] + 1);

            res = max(res, r - l + 1);
            last[s[r]] = r;
        }

        return res;
    }
};

int main() {

    cout << Solution().lengthOfLongestSubstring( "abcabcbb" )<<endl; //3
    cout << Solution().lengthOfLongestSubstring( "bbbbb" )<<endl;    //1
    cout << Solution().lengthOfLongestSubstring( "pwwkew" )<<endl;   //3
    cout << Solution().lengthOfLongestSubstring( "c" )<<endl;        //1
    cout << Solution().lengthOfLongestSubstring( "abba" )<<endl;     //2
    cout << Solution().lengthOfLongestSubstring( "" )<<endl;         //0

    return 0;
}