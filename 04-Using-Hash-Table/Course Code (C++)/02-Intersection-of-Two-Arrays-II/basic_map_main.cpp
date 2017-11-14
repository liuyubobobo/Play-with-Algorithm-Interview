#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

    map<int,int> myMap;
    if(myMap.find(42) == myMap.end())
        cout << "Can not find element 42" << endl;
    else
        cout << "Element 42 is in the map" << endl;

    cout << myMap[42] << endl; // 输出 0

    // 注意: 在C++中, map的key一旦被访问过, 就会添加默认的(key, value)对在map中!
    // 以下代码将找到42, 因为之前使用myMap[42]的方式对42进行了访问!
    if(myMap.find(42) == myMap.end())
        cout << "Can not find element 42" << endl;
    else
        cout << "Element 42 is in the map" << endl;

    myMap[42] ++;
    cout << myMap[42] << endl; // 输出 1
    if(myMap.find(42) == myMap.end())
        cout << "Can not find element 42" << endl;
    else
        cout << "Element 42 is in the map" << endl;

    myMap[42] --;
    cout << myMap[42] << endl; // 输出 0

    // 注意: key对应的值为0, 不代表key不存在
    if(myMap.find(42) == myMap.end())
        cout << "Can not find element 42" << endl;
    else
        cout << "Element 42 is in the map" << endl;

    // 使用erase删除一个key
    myMap.erase(42);
    if(myMap.find(42) == myMap.end())
        cout << "Can not find element 42" << endl;
    else
        cout << "Element 42 is in the map" << endl;

    return 0;
}