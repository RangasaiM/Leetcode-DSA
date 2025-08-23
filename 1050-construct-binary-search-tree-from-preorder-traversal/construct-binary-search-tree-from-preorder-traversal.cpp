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

    TreeNode* help(vector<int>& preorder,int& i,int bound){
        if(i==preorder.size() || bound<preorder[i]) return NULL;
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=help(preorder,i,preorder[i-1]);
        root->right=help(preorder,i,bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return help(preorder,i,INT_MAX);
    }
};