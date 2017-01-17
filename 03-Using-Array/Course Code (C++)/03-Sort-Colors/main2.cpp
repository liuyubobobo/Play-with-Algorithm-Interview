#include <iostream>
#include <vector>

using namespace std;


// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    void sortColors(vector<int> &A) {

        int zero = -1;      // [0...zero] == 0
        int two = A.size(); // [two...n-1] == 0
        for (int i = 0; i < two; ) {
            if( A[i] == 2 )
                swap( A[i] , A[--two] );
            else if( A[i] == 0 )
                swap( A[i++] , A[++zero] );
            else
                i ++;
        }
    }
};

int main() {

    int nums[] = {2, 2, 2, 1, 1, 0};
    vector<int> vec = vector<int>( nums , nums + sizeof(nums)/sizeof(int));

    Solution().sortColors( vec );
    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;

    return 0;
}
