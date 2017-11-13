/**
 * Created by liuyubobobo.
 */
public class Main2 {

    public static void main(String[] args) {

        // 数据规模倍乘测试selectionSort
        // O(n^2)
        System.out.println("Test for Selection Sort:");
        for( int i = 10 ; i <= 16 ; i ++ ){

            int n = (int)Math.pow(2,i);
            Integer[] arr = MyUtil.generateRandomArray(n, 0, 100000000);

            long startTime = System.currentTimeMillis();
            MyAlgorithmTester.selectionSort(arr, n);
            long endTime = System.currentTimeMillis();

            System.out.print("data size 2^" + i + " = " + n + "\t");
            System.out.println("Time cost: " + (endTime - startTime) + " ms");
        }
    }
}
