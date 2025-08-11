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

    int diameter(TreeNode* root,int& maxi){
        if(root==NULL) return 0;
        int l=diameter(root->left,maxi);
        int r=diameter(root->right,maxi);
        maxi=max(maxi,l+r+1);
        return 1+max(l,r);
        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        diameter(root,ans);
        return ans-1;
    }
};