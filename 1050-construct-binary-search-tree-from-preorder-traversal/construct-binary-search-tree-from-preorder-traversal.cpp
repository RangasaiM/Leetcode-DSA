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

    int getIndex(vector<int>& preorder,int k,int lo,int hi){
        for(int i=lo;i<=hi;i++){
            if(preorder[i]>preorder[k]){
                return i;
            }
        }
        return hi+1;
    }

    TreeNode* helper(vector<int>& preorder,int lo,int hi){
        if(lo>hi || hi>preorder.size()-1) return NULL;
        TreeNode* root=new TreeNode(preorder[lo]);
        int nextHigh=getIndex(preorder,lo,lo,hi);
        root->left=helper(preorder,lo+1,nextHigh-1);
        root->right=helper(preorder,nextHigh,hi);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder,0,preorder.size()-1);
    }
};