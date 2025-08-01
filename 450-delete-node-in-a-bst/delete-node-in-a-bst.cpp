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

    int InSuc(TreeNode* root){
        int mini=root->val;
        while(root!=NULL){
            mini=root->val;
            root=root->left;
        }
        return mini;
    }

    TreeNode*deleteRec(TreeNode* root,int key){
        if(root==NULL) return root;
        if(root->val<key){
            root->right=deleteRec(root->right,key);
        }
        else if(root->val>key){
            root->left=deleteRec(root->left,key);
        }
        else{
            if(root->left==NULL) return root->right;
            else if(root->right==NULL) return root->left;

            root->val=InSuc(root->right);
            root->right=deleteRec(root->right,root->val);
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteRec(root,key);
    }
};