/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        stack<TreeNode *> todo;
        unordered_map<TreeNode *, pair<bool, bool>> mp;
        mp[nullptr] = {false, false};
        todo.push(root);
        while (!todo.empty()) {
            TreeNode *node = todo.top();
            if (mp.find(node->right) == mp.end()) { todo.push(node->right); }
            else if (mp.find(node->left) == mp.end()) { todo.push(node->left); }
            else {
                mp[node] = {mp[node->right].first || mp[node->left].first,
                            mp[node->right].second || mp[node->left].second};
                if (node == p) { mp[node].first = true; }
                if (node == q) { mp[node].second = true; }
                if (mp[node] == make_pair(true, true)) { return node; }
                todo.pop();
            }
        }
        return nullptr;
    }
};