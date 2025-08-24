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

    void kth(TreeNode* root,int k,int& x,int& j){
        if(root==NULL) return;
        kth(root->left,k,x,j);
        x+=1;
        if(k==x){
            j=root->val;
            return;
        }
        kth(root->right,k,x,j);
    }

    int kthSmallest(TreeNode* root, int k) {
        int j=0;
        int x=0;
        kth(root,k,x,j);
        return j;
    }
};