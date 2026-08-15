package build_binary_tree_using_preorder_sequence;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

public class Main {
    private static int idx = -1;

    public static void main(String[] args) {
        idx = -1;
        int[] preorder = new int[]{1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

        TreeNode root = buildTree(preorder);

        // System.out.println(root.val);
        // System.out.println(root.left.val);
        // System.out.println(root.right.val);

        // ArrayList<Integer> res = buildPreorder(root);
        // System.out.println(Arrays.toString(res.toArray()));

        // System.out.println(
        //     verify(preorder, res.stream().mapToInt(Integer::intValue).toArray()) ? "\nPassed" : "\nFailed"
        // );

        // traversePreorder(root);
        traverseLevelOrder(root);
    }

    private static void traverseLevelOrder(TreeNode root) {
        if (root == null) return;

        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();

            System.out.println(node.val);
            if (node.left != null) queue.offer(node.left);
            if (node.right != null) queue.offer(node.right);
        }
    }

    private static void traversePreorder(TreeNode root) {
        if (root == null) return;

        System.out.println(root.val);
        traversePreorder(root.left);
        traversePreorder(root.right);
    }

    private static boolean verify(int[] list1, int[] list2) {
        if (list1.length != list2.length) return false;

        for (int i = 0; i < list1.length; i++) {
            if (list1[i] != list2[i]) return false;
        }

        return true;
    }

    private static TreeNode buildTree(int[] preorder) {
        if (preorder[++idx] == -1) return null;

        TreeNode root = new TreeNode(preorder[idx]);
        root.left = buildTree(preorder);
        root.right = buildTree(preorder);

        return root;
    }

    private static ArrayList<Integer> buildPreorder(TreeNode root) {
        if (root == null) return new ArrayList<>(List.of(-1));

        ArrayList<Integer> list = new ArrayList<>();
        list.add(root.val);

        ArrayList<Integer> leftList = buildPreorder(root.left);
        ArrayList<Integer> rightList = buildPreorder(root.right);

        list.addAll(leftList);
        list.addAll(rightList);

        return list;
    }
}
