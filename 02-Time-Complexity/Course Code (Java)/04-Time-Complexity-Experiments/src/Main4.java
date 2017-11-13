/**
 * Created by liuyubobobo.
 */
public class Main4 {

    public static void main(String[] args) {

        // 数据规模倍乘测试mergeSort
        // O(nlogn)
        System.out.println("Test for Merge Sort:");
        for( int i = 10 ; i <= 26 ; i ++ ){

            int n = (int)Math.pow(2,i);
            Integer[] arr = MyUtil.generateRandomArray(n, 0, 1<<30);

            long startTime = System.currentTimeMillis();
            MyAlgorithmTester.mergeSort(arr, n);
            long endTime = System.currentTimeMillis();

            System.out.print("data size 2^" + i + " = " + n + "\t");
            System.out.println("Time cost: " + (endTime - startTime) + " s");
        }
    }
}
