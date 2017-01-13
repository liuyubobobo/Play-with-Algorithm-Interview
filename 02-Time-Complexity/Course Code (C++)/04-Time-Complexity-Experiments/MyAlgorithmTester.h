//
// Created by liuyubobobo on 11/01/2017.
//

#ifndef INC_04_TIME_COMPLEXITY_EXPERIMENTS_MYALGORITHMTESTER_H
#define INC_04_TIME_COMPLEXITY_EXPERIMENTS_MYALGORITHMTESTER_H

#include <iostream>
#include <cassert>

using namespace std;

namespace MyAlgorithmTester{

    // O(logN)
    int binarySearch(int arr[], int n, int target){

        int l = 0, r = n-1;
        while( l <= r ){

            int mid = l + (r-l)/2;
            if( arr[mid] == target ) return mid;
            if( arr[mid] > target ) r = mid - 1;
            else l = mid + 1;
        }

        return -1;
    }

    // O(N)
    int findMax( int arr[], int n ){

        assert( n > 0 );

        int res = arr[0];
        for( int i = 1 ; i < n ; i ++ )
            if( arr[i] > res )
                res = arr[i];

        return res;
    }

    // O(NlogN)
    void __merge(int arr[], int l, int mid, int r, int aux[]){

        int i = l, j = mid+1;
        for( int k = l ; k <= r; k ++ ){

            if( i > mid )   { arr[k] = aux[j]; j ++;}
            else if( j > r ){ arr[k] = aux[i]; i ++;}
            else if( aux[i] < aux[j] ){ arr[k] = aux[i]; i ++;}
            else                      { arr[k] = aux[j]; j ++;}
        }
    }

    void mergeSort( int arr[], int n ){

        int *aux = new int[n];
        for( int i = 0 ; i < n ; i ++ )
            aux[i] = arr[i];

        for( int sz = 1; sz < n ; sz += sz )
            for( int i = 0 ; i < n ; i += sz+sz )
                __merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1), aux );

        delete[] aux;

        return;
    }

    // O(N^2)
    void selectionSort( int arr[], int n ){

        for(int i = 0 ; i < n ; i ++){
            int minIndex = i;
            for( int j = i + 1 ; j < n ; j ++ )
                if( arr[j] < arr[minIndex] )
                    minIndex = j;

            swap( arr[i] , arr[minIndex] );
        }

        return;
    }
}

#endif //INC_04_TIME_COMPLEXITY_EXPERIMENTS_MYALGORITHMTESTER_H
