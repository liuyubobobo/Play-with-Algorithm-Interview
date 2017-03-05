#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int m,n;
    vector<vector<bool>> visited;

    bool inArea( int x , int y ){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    // 从board[startx][starty]开始, 寻找word[index...word.size())
    bool searchWord( const vector<vector<char>> &board, const string& word, int index,
                    int startx, int starty ){

        //assert( inArea(startx,starty) );
        if( index == word.size() - 1 )
            return board[startx][starty] == word[index];

        if( board[startx][starty] == word[index] ){
            visited[startx][starty] = true;
            // 从startx, starty出发,向四个方向寻
            for( int i = 0 ; i < 4 ; i ++ ){
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                if( inArea(newx, newy) && !visited[newx][newy] &&
                    searchWord( board , word , index + 1 , newx , newy ) )
                    return true;
            }
            visited[startx][starty] = false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        assert( m > 0 );
        n = board[0].size();
        visited = vector<vector<bool> >(m,vector<bool>(n,false));
        for( int i = 0 ; i < board.size() ; i ++ )
            for( int j = 0 ; j < board[i].size() ; j ++ )
                if( searchWord( board, word, 0 , i, j) )
                    return true;

        return false;
    }
};

int main() {

    char b[3][4] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> board;
    for( int i = 0 ; i < 3 ; i ++ )
        board.push_back( vector<char>(b[i],b[i]+sizeof(b[i])/sizeof(char)) );

    int cases = 3;
    string words[3] = {"ABCCED" , "SEE" , "ABCB" };
    for( int i = 0 ; i < cases ; i ++ )
        if( Solution().exist(board,words[i]))
            cout<<"found "<<words[i]<<endl;
        else
            cout<<"can not found "<<words[i]<<endl;

    return 0;
}