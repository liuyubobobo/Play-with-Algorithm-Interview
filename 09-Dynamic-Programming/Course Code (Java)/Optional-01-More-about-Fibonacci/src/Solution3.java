/// 70. Climbing Stairs
/// https://leetcode.com/problems/climbing-stairs/description/
///
/// 对于第n个斐波那契数, 可以推导出其公式
/// Fn = 1/sqrt(5) * {[(1+sqrt(5))/2]^n - [(1-sqrt(5))/2]^n}
/// 具体推导过程, 有兴趣的同学可以自行在互联网上搜索学习。
/// 注意: 这个方法的时间复杂度依然是O(logn)的,因为数的幂运算也需要logn的时间
/// 但这个方法快于使用矩阵的幂运算符的方法
///
/// 时间复杂度: O(logn)
/// 空间复杂度: O(1)
public class Solution3 {

    public int climbStairs(int n) {

        if(n <= 0)
            throw new IllegalArgumentException("n must be greater than zero");

        if(n == 1)
            return 1;

        double sqrt5 = Math.sqrt(5.0);
        return (int)((Math.pow((1 + sqrt5) / 2, n + 1) - Math.pow((1 - sqrt5) / 2, n + 1)) / sqrt5);
    }

    public static void main(String[] args) {

        System.out.println((new Solution3()).climbStairs(10));
    }
}
