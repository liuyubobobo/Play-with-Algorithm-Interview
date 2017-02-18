#include <iostream>
#include <vector>

using namespace std;

/// 144. Binary Tree Preorder Traversal

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> res;
        __preorderTraversal( root , res );
        return res;
    }

private:
    void __preorderTraversal( TreeNode* node, vector<int> &res ){

        if( node ){
            res.push_back( node->val );
            __preorderTraversal( node->left, res );
            __preorderTraversal( node->right, res );
        }
    }
};

int main() {

    return 0;
}
