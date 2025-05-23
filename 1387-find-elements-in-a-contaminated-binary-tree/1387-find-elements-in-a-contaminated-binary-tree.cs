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
public class FindElements {
private readonly HashSet<int> values;
    public FindElements(TreeNode root) {
        values = new HashSet<int>();
Recover(root, 0);
    }
    
    public bool Find(int target) {
        return values.Contains(target);
    }
      private void Recover(TreeNode node, int value)
  {
      if (node == null) return;
      node.val = value;
      values.Add(value);
      Recover(node.left, 2 * value + 1);
      Recover(node.right, 2 * value + 2);
  }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * bool param_1 = obj.Find(target);
 */