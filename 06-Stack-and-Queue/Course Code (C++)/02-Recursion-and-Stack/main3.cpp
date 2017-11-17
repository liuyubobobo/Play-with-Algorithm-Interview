#include <iostream>
#include <vector>

using namespace std;

/// 145. Binary Tree Postorder Traversal
/// https://leetcode.com/problems/binary-tree-postorder-traversal/description/
/// 二叉树的后序遍历
/// 时间复杂度: O(n), n为树的节点个数
/// 空间复杂度: O(h), h为树的高度

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
        __postorderTraversal(root, res);
        return res;
    }

private:
    void __postorderTraversal(TreeNode* node, vector<int> &res){

        if( node ){
            __postorderTraversal(node->left, res);
            __postorderTraversal(node->right, res);
            res.push_back(node->val);
        }
    }
};

int main() {

    return 0;
}
