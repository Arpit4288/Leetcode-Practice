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
    public TreeNode RecoverFromPreorder(string traversal) {
          List<TreeNode> levels = new(); // keep track of the TreeNode that that depth
  for (int i = 0; i < traversal.Length;)
  {
      // read what depth this node is at
      int level = 0;
      while (traversal[i] == '-') { i++; level++; }
      // read what value it should have
      int val = 0;
      while (i < traversal.Length && traversal[i] != '-') val = val * 10 + traversal[i++] - '0';
      // create the node
      var node = new TreeNode(val);
      // add/set it to the levels list
      if (level < levels.Count) levels[level] = node; else levels.Add(node);
      // if it is not the root node, then connect this node to its parent
      if (level > 0)
      {
          var parent = levels[level - 1];
          if (parent.left != null)
          { // if parent's .left is already set
              parent.right = node;  // this is the .right child
          }
          else
          {
              parent.left = node;   // otherwise it is the .left child
          }
      }
  }
  return levels[0]; // return the root TreeNode
    }
}