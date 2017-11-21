/// 70. Climbing Stairs
/// https://leetcode.com/problems/climbing-stairs/description/
///
/// 在这一章的学习中, 我们看到了, 70号问题本质就是求斐波那契数
/// 只不过 climbStairs(n) 的答案, 对应第 n+1 个斐波那契数
/// 其中 f0 = 0, f(1) = 1, f(2) = 1, f(3) = 2...
/// 首先, 我们可以非常简单的使用O(1)的空间求出斐波那契数
/// 这个对空间的优化和我们在这个课程中所介绍的背包问题的空间优化, 其实是类似的思想
/// 我们对背包问题的空间优化, 从O(n^2)优化到了O(n)
/// 我们对斐波那契问题的优化,可以从O(n)优化到O(1)
/// 依靠的依然是, 求第n个斐波那契数, 我们只需要n-1和n-2两个斐波那契数,
/// 更小的斐波那契数不需要一直保存。
///
/// 时间复杂度: O(n)
/// 空间复杂度: O(1)
public class Solution1 {

    public int climbStairs(int n) {

        if(n <= 0)
            throw new IllegalArgumentException("n must be greater than zero");

        if(n == 1)
            return 1;

        int prev = 1, cur = 1;
        for(int i = 3 ; i <= n + 1; i ++){
            int f = cur + prev;
            prev = cur;
            cur = f;
        }
        return cur;
    }

    public static void main(String[] args) {

        System.out.println((new Solution1()).climbStairs(10));
    }
}
