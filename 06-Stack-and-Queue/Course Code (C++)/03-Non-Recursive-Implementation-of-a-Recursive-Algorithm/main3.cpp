#include <iostream>
#include <vector>

using namespace std;


/// 145. Binary Tree Postorder Traversal
/// https://leetcode.com/problems/binary-tree-postorder-traversal/description/
/// 非递归的二叉树的后序遍历
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

private:
    struct Command{
        string s;   // go, print
        TreeNode* node;
        Command(string s, TreeNode* node): s(s), node(node){}
    };

public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> res;
        if(root == NULL)
            return res;

        stack<Command> stack;
        stack.push(Command("go", root) );
        while(!stack.empty()){
            Command command = stack.top();
            stack.pop();

            if(command.s == "print")
                res.push_back(command.node->val);
            else{
                assert(command.s == "go");
                stack.push(Command("print", command.node));
                if(command.node->right)
                    stack.push(Command("go",command.node->right));
                if(command.node->left)
                    stack.push(Command("go",command.node->left));
            }
        }
        return res;
    }
};

int main() {

    return 0;
}

