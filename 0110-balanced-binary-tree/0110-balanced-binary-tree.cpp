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
    bool isBalanced(TreeNode *root) {
        if(root == nullptr){return true;}
        unordered_map<TreeNode *, int> depths;
        depths[nullptr] = 0;
        stack<TreeNode *> todo;
        todo.push(root);
        while (!todo.empty()) {
            TreeNode *node = todo.top();
            if (depths.find(node->left) == depths.end()) {
                todo.push(node->left);
            }
            else if (depths.find(node->right) == depths.end()) {
                todo.push(node->right);
            }
            else {
                depths[node] = 1 + max(depths[node->left], depths[node->right]);
                int diff = depths[node->left] - depths[node->right];
                if (diff > 1 || diff < -1) { return false; }
                todo.pop();
            }
        }
        return true;
    }
};