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

struct Command{
    string s;   // visit, print
    TreeNode* node;
    Command(string s, TreeNode* node): s(s), node(node){}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> res;
        if( root == NULL )
            return res;

        stack<Command> stack;
        stack.push( Command("visit", root) );
        while( !stack.empty() ){
            Command command = stack.top();
            stack.pop();

            if( command.s == "print" )
                res.push_back( command.node->val );
            else{
                assert( command.s == "visit" );
                stack.push( Command("print", command.node));
                if( command.node->right)
                    stack.push( Command("visit",command.node->right));
                if( command.node->left)
                    stack.push( Command("visit",command.node->left));
            }
        }
        return res;
    }
};

int main() {

    return 0;
}

