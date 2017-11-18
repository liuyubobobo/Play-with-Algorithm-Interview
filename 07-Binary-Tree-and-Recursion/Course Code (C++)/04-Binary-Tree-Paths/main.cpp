#include <iostream>
#include <string>
#include <vector>

using namespace std;


/// 257. Binary Tree Paths
/// https://leetcode.com/problems/binary-tree-paths/description/
/// 时间复杂度: O(n), n为树中的节点个数
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
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> res;

        if(root == NULL)
            return res;

        if(root->left == NULL && root->right == NULL){
            res.push_back(to_string(root->val));
            return res;
        }

        vector<string> leftPaths = binaryTreePaths(root->left);
        for(int i = 0 ; i < leftPaths.size() ; i ++)
            res.push_back(to_string(root->val) + "->" + leftPaths[i]);

        vector<string> rightPaths = binaryTreePaths(root->right);
        for(int i = 0 ; i < rightPaths.size() ; i ++)
            res.push_back(to_string(root->val) + "->" + rightPaths[i]);

        return res;
    }
};

int main() {

    return 0;
}