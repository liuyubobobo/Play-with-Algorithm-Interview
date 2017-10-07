import java.util.*;

// 时间复杂度 O(n)
// 空间复杂度 O(n)
class Solution {
    public void moveZeroes(int[] nums) {

        ArrayList<Integer> nonZeroElements = new ArrayList<Integer>();

        // 将vec中所有非0元素放入nonZeroElements中
        for( int i = 0 ; i < nums.size() ; i ++ )
            if( nums[i] )
                nonZeroElements.add( nums[i] );

        // 将nonZeroElements中的所有元素依次放入到nums开始的位置
        for( int i = 0 ; i < nonZeroElements.size() ; i ++ )
            nums[i] = nonZeroElements[i];

        // 将nums剩余的位置放置为0
        for( int i = nonZeroElements.size() ; i < nums.size() ; i ++ )
            nums[i] = 0;
    }
}