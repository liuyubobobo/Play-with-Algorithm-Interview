#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;

        if( root == NULL )
            return res;

        if( root->left == NULL && root->right == NULL ){
            res.push_back( to_string(root->val) );
            return res;
        }

        vector<string> v1 = binaryTreePaths(root->left);
        for( int i = 0 ; i < v1.size() ; i ++ )
            res.push_back( to_string(root->val) + "->" + v1[i] );

        vector<string> v2 = binaryTreePaths(root->right);
        for( int i = 0 ; i < v2.size() ; i ++ )
            res.push_back( to_string(root->val) + "->" + v2[i] );

        return res;
    }
};

int main() {

    return 0;
}