#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/description/
// 经典二叉树非递归前序遍历
// 时间复杂度: O(n), n 为二叉树节点个数
// 空间复杂度: O(h), h 为二叉树高度
class Solution {

public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> res;
        if(root == NULL)
            return res;

        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()){
            TreeNode* curNode = stack.top();
            stack.pop();
            res.push_back(curNode->val);

            if(curNode->right)
                stack.push(curNode->right);
            if(curNode->left)
                stack.push(curNode->left);
        }
        return res;
    }
};

int main() {

    return 0;
}
