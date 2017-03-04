#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Knapsack01{

private:
    vector<vector<int>> memo;

    int bestValue(const vector<int> &w, const vector<int> v, int index, int W){

        if( W == 0 || index < 0 )
            return 0;

        if( memo[index][W] != -1 )
            return memo[index][W];

        int res = bestValue(w, v, index-1, W);
        if( W >= w[index] )
            res = max( res , v[index] + bestValue(w, v, index-1, W-w[index]) );
        memo[index][W] = res;
        return res;
    }
public:
    int knapsack01(const vector<int> &w, const vector<int> &v, int W){
        assert( w.size() == v.size() );
        memo = vector<vector<int>>( w.size(), vector<int>(W+1,-1));
        return bestValue(w, v, w.size()-1, W);
    }
};

int main() {

    int n, W;
    cin>>n>>W;

    int v,w;
    vector<int> vs, ws;
    for( int i = 0 ; i < n ; i ++ ){
        cin>>w>>v;
        vs.push_back(v);
        ws.push_back(w);
    }

    cout<<Knapsack01().knapsack01(ws,vs,W)<<endl;
    return 0;
}