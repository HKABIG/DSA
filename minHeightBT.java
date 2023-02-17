**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
// The only difference between this and the maxHeight problem is that of accounting the
// Skewed binary trees in which case we need to take max of left or right.
class Solution {
    int minHeight(TreeNode root){
        if(root==null) return 0;
        int lHeight = minHeight(root.left);
        int rHeight = minHeight(root.right);
        if(lHeight==0 || rHeight==0) return 1+Math.max(lHeight,rHeight);
        return Math.min(lHeight,rHeight)+1;
    }
    public int minDepth(TreeNode root) {
        return minHeight(root);
    }
}