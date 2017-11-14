/// 让我们来测试使用Java中的TreeMap:)

import java.util.TreeMap;

public class Main {

    public static void main(String[] args) {

        TreeMap<Integer, Integer> myMap = new TreeMap<Integer, Integer>();
        if(myMap.containsKey(42))
            System.out.println("Element 42 is in the map");
        else
            System.out.println("Can not find element 42");

        System.out.println(myMap.get(42)); // 输出 null

        // Java不存在C++中默认的访问key即添加默认(key, value)的行为
        // 以下代码仍然无法找到42
        if(myMap.containsKey(42))
            System.out.println("Element 42 is in the map");
        else
            System.out.println("Can not find element 42");

        myMap.put(42, 0);
        myMap.put(42, myMap.get(42) + 1);
        System.out.println(myMap.get(42)); // 输出 1
        if(myMap.containsKey(42))
            System.out.println("Element 42 is in the map");
        else
            System.out.println("Can not find element 42");

        myMap.put(42, myMap.get(42) - 1);
        System.out.println(myMap.get(42)); // 输出 0

        // 注意: key对应的值为0, 不代表key不存在
        if(myMap.containsKey(42))
            System.out.println("Element 42 is in the map");
        else
            System.out.println("Can not find element 42");

        // 注意： 也不可以为key对应的值设置null来删除一个key
        myMap.put(42, null);
        if(myMap.containsKey(42))
            System.out.println("Element 42 is in the map");
        else
            System.out.println("Can not find element 42");

        // 使用remove删除一个key
        myMap.remove(42);
        if(myMap.containsKey(42))
            System.out.println("Element 42 is in the map");
        else
            System.out.println("Can not find element 42");
    }
}
