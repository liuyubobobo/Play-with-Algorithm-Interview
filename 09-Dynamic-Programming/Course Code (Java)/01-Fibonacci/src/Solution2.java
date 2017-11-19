import java.util.Arrays;

// 记忆化搜索
public class Solution2 {

    private int num = 0;

    public int fib(int n){

        int[] memo = new int[n + 1];
        Arrays.fill(memo, -1);
        return fib(n, memo);
    }

    private int fib(int n, int[] memo){

        num ++;

        if(n == 0)
            return 0;

        if(n == 1)
            return 1;

        if(memo[n] == -1)
            memo[n] = fib(n - 1, memo) + fib(n - 2, memo);

        return memo[n];
    }

    public int getNum(){
        return num;
    }

    public static void main(String[] args) {

        //int n = 42;
        int n = 1000; // 注意: 我们使用n = 1000只是为了测试性能, 实际上会溢出
                      // 斐波那契额数列是以指数速度上涨的

        Solution2 solution = new Solution2();
        long startTime = System.currentTimeMillis();
        int res = solution.fib(n);
        long endTime = System.currentTimeMillis();

        System.out.println("fib(" + n + ") = " + res);
        System.out.println("time : " + (endTime - startTime) + " ms");
        System.out.println("run function fib() " + solution.getNum() + " times.");
    }
}
