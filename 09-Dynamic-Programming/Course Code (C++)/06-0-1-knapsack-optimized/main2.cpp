#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Knapsack01{

public:
    int knapsack01(const vector<int> &w, const vector<int> &v, int W){
        assert( w.size() == v.size() );
        int n = w.size();
        vector<int> memo(W+1,0);

        for( int j = 0 ; j <= W ; j ++ )
            memo[j] = ( j >= w[0] ? v[0] : 0 );

        for( int i = 1 ; i < n ; i ++ )
            for( int j = W ; j >= w[i] ; j -- )
                memo[j] = max( memo[j], v[i] + memo[j-w[i]]);

        return memo[W];
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