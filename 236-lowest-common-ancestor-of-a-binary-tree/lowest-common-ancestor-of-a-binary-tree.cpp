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

    bool findPath(TreeNode* root,TreeNode* k,vector<TreeNode*>& path){
        if(root==NULL) return false;

        path.push_back(root);
        if(root==k) return true;
        if(findPath(root->left,k,path)||findPath(root->right,k,path)) return true;
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a;
        vector<TreeNode*> b;
        findPath(root,p,a);
        findPath(root,q,b);
        int n=min(a.size(),b.size());
        for(int i=0;i<n;i++){
            cout<<a[i]->val;
            if(a[i]!=b[i]){
                return a[i-1];
            }
        }
        return a[n-1];
    }
};