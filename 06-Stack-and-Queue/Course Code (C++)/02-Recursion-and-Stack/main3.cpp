#include <iostream>
#include <vector>

using namespace std;

/// 145. Binary Tree Postorder Traversal

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> res;
        __postorderTraversal( root , res );
        return res;
    }

private:
    void __postorderTraversal( TreeNode* node, vector<int> &res ){

        if( node ){
            __postorderTraversal( node->left, res );
            __postorderTraversal( node->right, res );
            res.push_back( node->val );
        }
    }
};

int main() {

    return 0;
}
