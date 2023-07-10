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
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int r_ans = dfs(root->right);
        int l_ans = dfs(root->left);
        if (r_ans == 0) return l_ans + 1;
        else if (l_ans == 0) return r_ans + 1;
        else return min(l_ans, r_ans) + 1;
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int ans;
        ans = dfs(root);
        return ans;
    }

};