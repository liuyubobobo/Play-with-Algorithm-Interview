// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//
// 课程问答区 @yatkun 提出的方法,
// l每次可以向前跳跃, 而不仅仅是+1
// 但代价是, 为了获得这个跳跃的位置, 每次需要遍历整个窗口的字符串
//
// 时间复杂度: O(len(s)*len(charset))
// 空间复杂度: O(1)
public class Solution4{

    public int lengthOfLongestSubstring(String s) {

        int l = 0, r = 0; //滑动窗口为s[l...r]
        int res = 0;

        while(r < s.length()){

            int index = isDuplicateChar(s, l, r);

            // 如果s[r]之前出现过
            // l可以直接跳到s[r+1]之前出现的位置 + 1的地方
            if(index != -1)
                l = index + 1;

            res = Math.max(res, r-l+1);
            r ++;
        }

        return res;
    }

    // 查看s[l...r-1]之间是否存在s[r]
    // 若存在,返回相应的索引, 否则返回-1
    private int isDuplicateChar(String s, int l, int r){
        for(int i = l ; i < r ; i ++)
            if(s.charAt(i) == s.charAt(r))
                return i;
        return -1;
    }

    public static void main(String[] args) {

        System.out.println((new Solution4()).lengthOfLongestSubstring( "abcabcbb" ));
        System.out.println((new Solution4()).lengthOfLongestSubstring( "bbbbb" ));
        System.out.println((new Solution4()).lengthOfLongestSubstring( "pwwkew" ));
        System.out.println((new Solution4()).lengthOfLongestSubstring( "" ));
    }
}
