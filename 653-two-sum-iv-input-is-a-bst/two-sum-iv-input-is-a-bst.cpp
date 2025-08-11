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

    void inorder(TreeNode* root,vector<int>& s){
        if(root==NULL) return;
        inorder(root->left,s);
        s.push_back(root->val);
        inorder(root->right,s);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> s;
        inorder(root,s);
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]+s[r]==k) return true;
            else if(s[l]+s[r]>k) r--;
            else l++;
        }
        return false;
    }
};