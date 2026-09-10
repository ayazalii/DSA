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
// class Solution {
// public:
//     int averageOfSubtree(TreeNode* root, int & count) {
//         if(root==nullptr) return {0,0};

//         auto [leftsum,leftcount]=trav(root->left,count);
//         auto[rightsum,rightcount]=trav(root->right,count);

//         int subtreesum=leftsum+rightsum+root->val;
//         int subtreecount=leftcount + rightcount + 1;

//         if(subtreesum/subtreecount==root->val) count++;
//         return{subtree,subtreecount};
//     }
//     int 
// };
class Solution {
public:
    pair<int, int> trav(TreeNode* root, int& count) {
        if(root == nullptr) return {0, 0};

        auto [leftSum, leftCount] = trav(root->left, count);
        auto [rightSum, rightCount] = trav(root->right, count);

        int subtreeSum = leftSum + rightSum + root->val;
        int subtreeCount = leftCount + rightCount + 1;

        if(subtreeSum / subtreeCount == root->val) count++;

        return {subtreeSum, subtreeCount};
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        trav(root, count);
        return count;
    }
};