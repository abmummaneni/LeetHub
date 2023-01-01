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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root, int depth = 0) {
        if (root == nullptr){return {};}
        while (ans.size() <= depth){ans.emplace_back();}
        ans[depth].push_back(root->val);
        depth++;
        levelOrder(root->left, depth);
        levelOrder(root->right, depth);
        return ans;
    }
};