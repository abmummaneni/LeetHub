/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool isSubtree(TreeNode *root, TreeNode *subRoot, bool tunnel = false) {
    if (root == nullptr || subRoot == nullptr) { return root == nullptr && subRoot == nullptr && tunnel; }
    if (tunnel) {
        if (root->val != subRoot->val){return false;}
        else{return isSubtree(root->right, subRoot->right, true) && isSubtree(root->left, subRoot->left, true);}
    }
    if (root->val == subRoot->val) {
        return isSubtree(root->right, subRoot->right, true) && isSubtree(root->left, subRoot->left, true) ||
               isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
    }
    else { return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot); }
}
};