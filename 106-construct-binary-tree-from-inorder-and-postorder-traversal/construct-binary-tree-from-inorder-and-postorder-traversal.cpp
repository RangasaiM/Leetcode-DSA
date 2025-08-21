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
    TreeNode* bTree(vector<int>& inorder,unordered_map<int,int>& inmap,int inStart,int inEnd,vector<int>& postorder,int pStart,int pEnd){
        if(inStart > inEnd || pStart > pEnd) return NULL;

        TreeNode* root=new TreeNode(postorder[pEnd]);
        int inIndex=inmap[root->val];
        int atRight=inEnd-inIndex;
        root->left=bTree(inorder,inmap,inStart,inIndex-1,postorder,pStart,pEnd - atRight - 1);
        root->right=bTree(inorder,inmap,inIndex+1,inEnd,postorder,pEnd-atRight,pEnd-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inmap;
        int n=inorder.size();
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        TreeNode* root=bTree(inorder,inmap,0,n-1,postorder,0,n-1);
        return root;
    }
};