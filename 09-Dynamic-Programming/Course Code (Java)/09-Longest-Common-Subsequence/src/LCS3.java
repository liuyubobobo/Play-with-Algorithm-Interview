/// LCS问题
/// 动态规划, 躲避边界条件
/// 时间复杂度: O(len(s1)*len(s2))
/// 空间复杂度: O(len(s1)*len(s2))
public class LCS3 {

    public String lcs(String s1, String s2){

        int m = s1.length();
        int n = s2.length();

        // memo 是 (m + 1) * (n + 1) 的动态规划表格
        // memo[i][j] 表示s1的前i个字符和s2前j个字符的最长公共子序列的长度
        // 其中memo[0][j] 表示s1取空字符串时, 和s2的前j个字符作比较
        // memo[i][0] 表示s2取空字符串时, 和s1的前i个字符作比较
        // 所以, memo[0][j] 和 memo[i][0] 均取0
        // 我们不需要对memo进行单独的边界条件处理 :-)
        int[][] memo = new int[m + 1][n + 1];

        // 动态规划的过程
        // 注意, 由于动态规划状态的转变, 下面的i和j可以取到m和n
        for(int i = 1 ; i <= m ; i ++)
            for(int j = 1 ; j <= n ; j ++)
                if(s1.charAt(i - 1) == s2.charAt(j - 1))
                    memo[i][j] = 1 + memo[i - 1][j - 1];
                else
                    memo[i][j] = Math.max(memo[i - 1][j], memo[i][j - 1]);

        // 通过memo反向求解s1和s2的最长公共子序列
        m = s1.length();
        n = s2.length();
        StringBuilder res = new StringBuilder("");
        while(m > 0 && n > 0)
            if(s1.charAt(m - 1) == s2.charAt(n - 1)){
                res.insert(0, s1.charAt(m - 1));
                m --;
                n --;
            }
            else if(memo[m - 1][n] > memo[m][n - 1])
                m --;
            else
                n --;

        return res.toString();
    }

    public static void main(String[] args) {

        String s1 = "ABCDGH";
        String s2 = "AEDFHR";
        System.out.println((new LCS3()).lcs(s1, s2));

        s1 = "AAACCGTGAGTTATTCGTTCTAGAA";
        s2 = "CACCCCTAAGGTACCTTTGGTTC";
        System.out.println((new LCS3()).lcs(s1, s2));
    }
}
