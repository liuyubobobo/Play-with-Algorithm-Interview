/**
 * Created by liuyubobobo.
 */
public class MyAlgorithmTester {

    private MyAlgorithmTester(){}

    // O(logN)
    public static int binarySearch(Comparable arr[], int n, Comparable target){

        int l = 0, r = n - 1;
        while(l <= r){

            int mid = l + (r - l) / 2;
            if(arr[mid].compareTo(target) == 0) return mid;
            if(arr[mid].compareTo(target) > 0 ) r = mid - 1;
            else l = mid + 1;
        }

        return -1;
    }

    // O(N)
    public static Integer findMax(Integer[] arr, int n){

        assert n > 0;

        Integer res = arr[0];
        for(int i = 1 ; i < n ; i ++)
            if(arr[i]> res)
                res = arr[i];
        return res;
    }

    // O(NlogN)
    public static void mergeSort(Comparable[] arr, int n ){

        Comparable[] aux = new Comparable[n];
        for(int i = 0 ; i < n ; i ++)
            aux[i] = arr[i];

        for(int sz = 1; sz < n ; sz += sz)
            for(int i = 0 ; i < n ; i += sz+sz)
                merge(arr, i, i + sz - 1, Math.min(i + sz + sz - 1, n - 1), aux);

        return;
    }

    private static void merge(Comparable[] arr, int l, int mid, int r, Comparable[] aux){

        for(int i = l ; i <= r ; i ++)
            aux[i] = arr[i];

        int i = l, j = mid + 1;
        for( int k = l ; k <= r; k ++ ){

            if(i > mid)   { arr[k] = aux[j]; j ++;}
            else if(j > r){ arr[k] = aux[i]; i ++;}
            else if(aux[i].compareTo(aux[j]) < 0){ arr[k] = aux[i]; i ++;}
            else          { arr[k] = aux[j]; j ++;}
        }
    }

    // O(N^2)
    public static void selectionSort(Comparable[] arr, int n ){

        for(int i = 0 ; i < n ; i ++){
            int minIndex = i;
            for( int j = i + 1 ; j < n ; j ++ )
                if(arr[j].compareTo(arr[minIndex]) < 0)
                    minIndex = j;

            swap(arr, i, minIndex);
        }

        return;
    }

    private static void swap(Object[] arr, int i, int j){

        if(i < 0 || i >= arr.length)
            throw new IllegalArgumentException("i is out of bound");

        if(j < 0 || j >= arr.length)
            throw new IllegalArgumentException("j is out of bound");

        Object t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}
