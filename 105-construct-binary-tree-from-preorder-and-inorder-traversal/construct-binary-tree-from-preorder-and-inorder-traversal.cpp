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
    TreeNode* helper(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>& mp){
        if(preStart>preEnd || inStart>inEnd) return NULL;

        TreeNode* root=new TreeNode(preorder[preStart]);
        int inIndex=mp[preorder[preStart]];
        int numsLeft=inIndex-inStart;
        root->left=helper(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inIndex-1,mp);
        root->right=helper(preorder,preStart+numsLeft+1,preEnd,inorder,inIndex+1,preEnd,mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        int n=preorder.size();
        int m=inorder.size();
        for(int i=0;i<m;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* ans;
        ans=helper(preorder,0,n-1,inorder,0,n-1,mp);
        return ans;
    }
};