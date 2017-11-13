//
// Created by liuyubobobo on 12/01/2017.
//

#ifndef INC_06_AMORTIZED_TIME_MYVECTOR_H
#define INC_06_AMORTIZED_TIME_MYVECTOR_H

template <typename T>
class MyVector{

private:
    T* _data;
    int _size;       // 存储数组中的元素个数
    int _capacity;   // 存储数组中可以容纳的最大的元素个数

    // 复杂度为 O(n)
    void resize(int newCapacity){

        assert(newCapacity >= _size);
        T *newData = new T[newCapacity];
        for(int i = 0 ; i < _size ; i ++)
            newData[i] = _data[i];
        delete[] _data;

        _data = newData;
        _capacity = newCapacity;
    }

public:
    MyVector(int cap): _size(0), _capacity(cap){
        _data = new T[_capacity];
    }

    MyVector(): MyVector(10){}

    ~MyVector(){

        delete[] _data;
    }

    // 平均复杂度为 O(1)
    void push_back(T e){

        if( _size == _capacity )
            resize( 2 * _capacity );

        _data[_size++] = e;
    }

    // 平均复杂度为 O(1)
    T pop_back(){

        assert(_size > 0);
        T ret = _data[_size-1];
        _size --;

        // 在size达到静态数组最大容量的1/4时才进行resize
        // resize的容量是当前最大容量的1/2
        // 防止复杂度的震荡
        if(_size == _capacity / 4)
            resize(_capacity / 2);

        return ret;
    }

    T operator[](int index){
        assert(index >= 0 && index < _size);
        return _data[index];
    }

    T back(){
        assert(_size > 0);
        return _data[_size-1];
    }

    int size(){
        return _size;
    }

    int capacity(){
        return _capacity;
    }
};

#endif //INC_06_AMORTIZED_TIME_MYVECTOR_H
