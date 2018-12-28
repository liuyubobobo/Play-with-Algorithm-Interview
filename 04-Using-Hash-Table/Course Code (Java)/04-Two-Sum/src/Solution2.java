import java.util.HashMap;

// 1. Two Sum
// https://leetcode.com/problems/two-sum/description/
//
// 感谢课程中的 @Charles_Zhang 提出:
// 由于题目中只要求求出唯一的一个解。因此可以在最初的时候遍历整个数组, 将数组中的每个数字的索引放在map中。
// 此时, record中记录的永远是每一个数字最后出现的位置。
// 而对于 target = 2*a的情况, 如果nums中有两个或两个以上a,
// 我们在扫描时会先看到第一个a, 而从record中拿到的是最后一个a :)
//
// 时间复杂度：O(n)
// 空间复杂度：O(n)
public class Solution2 {

    public int[] twoSum(int[] nums, int target) {

        HashMap<Integer, Integer> record = new HashMap<Integer, Integer>();
        for(int i = 0 ; i < nums.length ; i ++)
            record.put(nums[i], i);

        for(int i = 0 ; i < nums.length; i ++){

            Integer index = record.get(target - nums[i]);
            if(index != null && index != i){
                int[] res = {i, index};
                return res;
            }
        }

        throw new IllegalStateException("the input has no solution");
    }

    private static void printArr(int[] nums){
        for(int num: nums)
            System.out.print(num + " ");
        System.out.println();
    }

    public static void main(String[] args) {

        int[] nums = {0,4,3,0};
        int target = 0;
        printArr((new Solution()).twoSum(nums, target));
    }
}
