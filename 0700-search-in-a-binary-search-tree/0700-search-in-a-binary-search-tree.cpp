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
    TreeNode* searchBST(TreeNode* root, int target) {
        if(root==NULL) return NULL;
        TreeNode* curr=root;

        while(curr!=NULL) {
            if(target<curr->val){
                //left subtree
                curr=curr->left;
            }
            else if(target>curr->val){
                //right subtree
                curr=curr->right;
            }
            else{
                return curr;
            }
        }
            return NULL;
    }
};