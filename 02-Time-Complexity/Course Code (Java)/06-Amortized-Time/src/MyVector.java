import java.util.Arrays;

/**
 * Created by liuyubobobo.
 */
public class MyVector<Item> {

    private Item[] data;
    private int size;       // 存储数组中的元素个数
    private int capacity;   // 存储数组中可以容纳的最大的元素个数

    public MyVector(){
        data = (Item[])new Object[100];
        size = 0;
        capacity = 100;
    }

    // 平均复杂度为 O(1)
    public void push_back(Item e){

        if(size == capacity)
            resize(2 * capacity);

        data[size++] = e;
    }

    // 平均复杂度为 O(1)
    public Item pop_back(){

        if(size <= 0)
            throw new IllegalArgumentException("can not pop back for empty vector.");

        size --;
        return data[size];
    }

    // 复杂度为 O(n)
    private void resize(int newCapacity){

        assert newCapacity >= size;
        Item[] newData = (Item[])new Object[newCapacity];
        for(int i = 0 ; i < size ; i ++)
            newData[i] = data[i];

        data = newData;
        capacity = newCapacity;
    }

    public static void main(String[] args) {

        for( int i = 10 ; i <= 26 ; i ++ ){

            int n = (int)Math.pow(2,i);

            long startTime = System.currentTimeMillis();
            MyVector<Integer> vec = new MyVector<Integer>();
            for(int num = 0 ; num < n ; num ++){
                vec.push_back(num);
            }
            long endTime = System.currentTimeMillis();

            System.out.print(n + " operations: \t");
            System.out.println((endTime - startTime) + " ms");
        }
    }
}
