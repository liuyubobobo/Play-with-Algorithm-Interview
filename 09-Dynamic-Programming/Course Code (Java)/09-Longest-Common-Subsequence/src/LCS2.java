/// LCS问题
/// 动态规划
/// 时间复杂度: O(len(s1)*len(s2))
/// 空间复杂度: O(len(s1)*len(s2))
public class LCS2 {

    public String lcs(String s1, String s2){

        int m = s1.length();
        int n = s2.length();

        // 对memo的第0行和第0列进行初始化
        int[][] memo = new int[m][n];
        for(int j = 0 ; j < n ; j ++)
            if(s1.charAt(0) == s2.charAt(j)){
                for(int k = j ; k < n ; k ++)
                    memo[0][k] = 1;
                break;
            }

        for(int i = 0 ; i < m ; i ++)
            if(s1.charAt(i) == s2.charAt(0)) {
                for(int k = i ; k < m ; k ++)
                    memo[k][0] = 1;
                break;
            }

        // 动态规划的过程
        for(int i = 1 ; i < m ; i ++)
            for(int j = 1 ; j < n ; j ++)
                if(s1.charAt(i) == s2.charAt(j))
                    memo[i][j] = 1 + memo[i-1][j-1];
                else
                    memo[i][j] = Math.max(memo[i-1][j], memo[i][j-1]);

        // 通过memo反向求解s1和s2的最长公共子序列
        m = s1.length() - 1;
        n = s2.length() - 1;
        StringBuilder res = new StringBuilder("");
        while(m >= 0 && n >= 0)
            if(s1.charAt(m) == s2.charAt(n)){
                res.insert(0, s1.charAt(m));
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

        return res.toString();
    }

    public static void main(String[] args) {

        String s1 = "ABCDGH";
        String s2 = "AEDFHR";
        System.out.println((new LCS2()).lcs(s1, s2));

        s1 = "AAACCGTGAGTTATTCGTTCTAGAA";
        s2 = "CACCCCTAAGGTACCTTTGGTTC";
        System.out.println((new LCS2()).lcs(s1, s2));
    }
}
