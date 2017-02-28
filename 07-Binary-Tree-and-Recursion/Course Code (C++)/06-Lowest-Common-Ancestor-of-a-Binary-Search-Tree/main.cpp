#include <iostream>
#include <cassert>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        assert( p != NULL && q != NULL );

        if( root == NULL )
            return NULL;

        if( p->val < root->val && q->val < root->val )
            return lowestCommonAncestor( root->left, p, q);
        if( p->val > root->val && q->val > root->val )
            return lowestCommonAncestor( root->right, p, q);

        assert( p->val == root->val || q->val == root->val
                || (root->val-p->val)*(root->val-q->val) < 0 );

        return root;
    }
};

int main() {

    return 0;
}