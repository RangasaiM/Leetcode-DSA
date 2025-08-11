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

    TreeNode* helper(TreeNode* root,TreeNode*p,TreeNode*q){
        if(root==NULL || root==p || root==q){
            return root;
        }

        auto l=helper(root->left,p,q);
        auto r=helper(root->right,p,q);

        if(l==NULL) return r;
        else if(r==NULL) return l;
        else{
            return root;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto ans=helper(root,p,q);
        return ans;
    }
};