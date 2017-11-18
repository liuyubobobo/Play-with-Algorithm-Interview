import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/description/
// 经典二叉树非递归前序遍历
// 时间复杂度: O(n), n 为二叉树节点个数
// 空间复杂度: O(h), h 为二叉树高度
public class Solution {

    // Definition for a binary tree node.
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public List<Integer> preorderTraversal(TreeNode root) {

        ArrayList<Integer> res = new ArrayList<Integer>();
        if(root == null)
            return res;

        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.push(root);
        while(!stack.empty()){
            TreeNode curNode = stack.pop();
            res.add(curNode.val);

            if(curNode.right != null)
                stack.push(curNode.right);
            if(curNode.left != null)
                stack.push(curNode.left);
        }
        return res;
    }

}
