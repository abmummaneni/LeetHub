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
    int goodNodes(TreeNode *root) {
        unordered_map<TreeNode *, int> mp;
        mp[root] = INT_MIN;
        maxBefore(root, mp);
        int ans = 0;
        for (const auto &[node, maxPrev]: mp) {
            if (node != nullptr && node->val >= maxPrev) { ans++; }
        }
        return ans;
    }

    void maxBefore(TreeNode *root, unordered_map<TreeNode *, int> &mp) {
        if (root == nullptr) { return; };
        mp[root->right] = max(root->val, mp[root]);
        mp[root->left] = max(root->val, mp[root]);
        maxBefore(root->right, mp);
        maxBefore(root->left, mp);
    }
};