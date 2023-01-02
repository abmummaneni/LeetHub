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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        recurRight(root, ans, 0);
        return ans;
    }

    void recurRight(TreeNode* root, vector<int> &ans, int depth){
        if (root == nullptr){return;}
        if (depth >= ans.size()){ans.push_back(root->val);}
        depth++;
        recurRight(root->right, ans, depth);
        recurRight(root->left, ans, depth);
    }

};