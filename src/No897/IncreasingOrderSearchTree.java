package No897;

import java.util.ArrayList;
import java.util.Stack;

/**
 * @author Kenway
 * @date 4/25/2021 11:54 AM
 * @description
 **/

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public TreeNode increasingBST(TreeNode root) {
        ArrayList<Integer> res= new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;
        while (cur != null || !stack.empty()) {
            while (cur != null) {
                stack.push(cur);
                cur = cur.left;
            }

            cur = stack.pop();
            res.add(cur.val);
            cur = cur.right;
        }

        TreeNode head = new TreeNode(res.get(0)), p = head;
        for (int i = 1; i < res.size(); i++) {
            p.right = new TreeNode(res.get(i));
            p = p.right;
        }

        return head;
    }
}


public class IncreasingOrderSearchTree {
    public static void main(String[] args) {

    }
}
