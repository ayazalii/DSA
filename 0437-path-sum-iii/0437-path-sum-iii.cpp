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
    int ans = 0;
    unordered_map<long, int> mp;

    void dfs(TreeNode* root, long curSum, int target) {
        if (!root) return;

        curSum += root->val;

        if (curSum == target) ans++;
        if (mp.count(curSum - target)) ans += mp[curSum - target];

        mp[curSum]++;

        dfs(root->left, curSum, target);
        dfs(root->right, curSum, target);

        mp[curSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        dfs(root, 0, targetSum);
        return ans;
    }
};
