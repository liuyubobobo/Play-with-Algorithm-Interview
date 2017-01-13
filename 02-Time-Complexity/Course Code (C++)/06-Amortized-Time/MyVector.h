//
// Created by liuyubobobo on 12/01/2017.
//

#ifndef INC_06_AMORTIZED_TIME_MYVECTOR_H
#define INC_06_AMORTIZED_TIME_MYVECTOR_H

template <typename T>
class MyVector{

private:
    T* data;
    int size;       // 存储数组中的元素个数
    int capacity;   // 存储数组中可以容纳的最大的元素个数

    // O(n)
    void resize(int newCapacity){

        assert( newCapacity >= size );
        T *newData = new T[newCapacity];
        for( int i = 0 ; i < size ; i ++ )
            newData[i] = data[i];
        delete[] data;

        data = newData;
        capacity = newCapacity;
    }

public:
    MyVector(){

        data = new T[100];
        size = 0;
        capacity = 100;
    }

    ~MyVector(){

        delete[] data;
    }

    // Average: O(1)
    void push_back(T e){

        if( size == capacity )
            resize( 2* capacity );

        data[size++] = e;
    }

    // O(1)
    T pop_back(){

        assert( size > 0 );
        size --;

        return data[size];
    }

};

#endif //INC_06_AMORTIZED_TIME_MYVECTOR_H
