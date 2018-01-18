import java.util.Arrays;

/// 455. Assign Cookies
/// https://leetcode.com/problems/assign-cookies/description/
/// 先尝试满足最不贪心的小朋友
/// 时间复杂度: O(nlogn)
/// 空间复杂度: O(1)
public class Solution2 {

    public int findContentChildren(int[] g, int[] s) {

        Arrays.sort(g);
        Arrays.sort(s);

        int gi = 0, si = 0;
        int res = 0;
        while(gi < g.length && si < s.length){
            if(s[si] >= g[gi]){
                res ++;
                gi ++;
            }
            si ++;
        }

        return res;
    }

    public static void main(String[] args) {

        int g1[] = {1, 2, 3};
        int s1[] = {1, 1};
        System.out.println((new Solution2()).findContentChildren(g1, s1));

        int g2[] = {1, 2};
        int s2[] = {1, 2, 3};
        System.out.println((new Solution2()).findContentChildren(g2, s2));
    }
}
