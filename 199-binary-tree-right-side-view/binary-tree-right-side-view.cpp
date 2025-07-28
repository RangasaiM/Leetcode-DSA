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

    void rightView(TreeNode* node,int level,vector<int>& right){
        if(node==nullptr) return;
        if(level==right.size()) right.push_back(node->val);
        rightView(node->right,level+1,right);
        rightView(node->left,level+1,right);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> right;
        rightView(root,0,right);
        return right;
    }
};