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

    int maxSum(TreeNode* root,int& ans){
        if(root==NULL) return 0;
        int l=max(0,maxSum(root->left,ans));
        int r=max(0,maxSum(root->right,ans));
        ans=max(ans,l+r+root->val);
        return root->val+max(l,r);
    }

    int maxPathSum(TreeNode* root) {
        int ans=root->val;
        int x=maxSum(root,ans);
        return ans;
    }
};