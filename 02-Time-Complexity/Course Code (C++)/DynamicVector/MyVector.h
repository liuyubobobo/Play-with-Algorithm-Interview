//
// Created by liuyubobobo on 12/01/2017.
//

#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <cassert>

using namespace std;


template <typename T>
class MyVector {

private:
    T* _data;
    int _capacity;   // 存储数组中可以容纳的最大的元素个数
    int _size;       // 存储数组中的元素个数

    // O(n)
    void resize( int newCapacity ){

        assert( newCapacity >= _size );
        T *newData = new T[newCapacity];
        for( int i = 0 ; i < _size ; i ++ )
            newData[i] = _data[i];
        delete[] _data;

        _data = newData;
        _capacity = newCapacity;
    }

public:

    MyVector(int cap):_size(0), _capacity(cap){
        _data = new T[_capacity];
    }

    MyVector(): MyVector(10){}

    ~MyVector(){
        delete[] _data;
    }

    // Average: O(1)
    void push_back(T e){

        //assert( size < capacity );
        if( _size == _capacity )
            resize( 2*_capacity );

        _data[_size++] = e;
    }

    // Average: O(1)
    T pop_back(){

        assert( _size > 0 );
        T ret = _data[--_size];
        if( _size == _capacity/4 )
            resize( _capacity/2 );

        return ret;
    }

    int size(){ return _size;}
    int capacity(){ return _capacity;}
};

#endif //MYVECTOR_H
