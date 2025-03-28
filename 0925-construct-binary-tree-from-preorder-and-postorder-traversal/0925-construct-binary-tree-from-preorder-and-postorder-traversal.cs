/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public TreeNode ConstructFromPrePost(int[] preorder, int[] postorder) {
         return ConstructFromPrePost(preorder, postorder, 0, preorder.Length - 1, 0, postorder.Length - 1);
    }

    private TreeNode ConstructFromPrePost(int[] pre, int[] post, int preLeft, int preRight, int postLeft, int postRight)
{
    var length = preRight - preLeft;
    if (length < 0) return null;
    var root = new TreeNode(pre[preLeft]);
    if (length == 0) return root;

    var newPostRight = postRight - 1;
    while (post[newPostRight] != pre[preLeft + 1])
        newPostRight--;
    var newLength = newPostRight - postLeft + 1;

    root.left = ConstructFromPrePost(pre, post, preLeft + 1, preLeft + newLength, postLeft, newPostRight);
    root.right = ConstructFromPrePost(pre, post, preLeft + newLength + 1, preRight, newPostRight + 1, postRight - 1);
    return root;
}
    
}