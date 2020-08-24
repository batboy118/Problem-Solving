/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function isValidBST(root: TreeNode | null): boolean {
  let stack: TreeNode[] = [];
  let cmp = -9876543210;
  while(stack.length || root){
      while(root){
          stack.push(root);
          root = root.left;
      }
      root = stack[stack.length - 1];
      stack.pop();
      if(root.val <= cmp)return false;
      cmp = root.val;
      root = root.right;
  }
  return true;
};
