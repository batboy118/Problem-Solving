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

//재귀 이용

function checkSymmetric(node1: TreeNode | null, node2: TreeNode | null): boolean {
    if(node1 === null && node2 === null) return true;
    if(node1 === null || node2 === null) return false;
    return node1.val === node2.val && checkSymmetric(node1.right, node2.left) && checkSymmetric(node1.left, node2.right)
}

function isSymmetric(root: TreeNode | null): boolean {
    if(root === null) return true;
    return checkSymmetric(root.left, root.right)
};


// 배열 이용

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

function isSymmetric(root: TreeNode | null): boolean {
    if(root === null) return true;
    const left = [root.left];
    const right = [root.right];
    let i = 0;
    while(left.length > i && right.length > i){
        if(left.length !== right.length) return false;
        let lNode = left[i];
        let rNode = right[i];
        if((lNode !== null && rNode !== null) && (lNode.val !== rNode.val)) return false;
        if((lNode === null &&  rNode !== null)|| (lNode !== null &&  rNode === null)) return false;
        if(lNode !== null){
            left.push(lNode.left);
            left.push(lNode.right);
        }
        if(rNode !== null){
            right.push(rNode.right);
            right.push(rNode.left);
        }
        i++;
    }
    return true;
};
