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
int ans=0;
unordered_map<long,int> mp;
    void dfs(TreeNode* root,long cursum, int target) {
        if(!root) return;

        cursum+=root->val;

        if(cursum == target) ans++;
        if(mp.count(cursum-target)) ans+=mp[cursum-target];
        mp[cursum]++;

        dfs(root->left,cursum,target);
        dfs(root->right,cursum,target);

        mp[cursum]--;
    }
int pathSum(TreeNode* root,int targetsum)
{
    dfs(root,0,targetsum);
    return ans;
}
};