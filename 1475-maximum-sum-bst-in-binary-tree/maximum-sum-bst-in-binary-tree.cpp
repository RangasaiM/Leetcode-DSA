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

class Node{
public:
    int sum;
    int mini;
    int maxi;
    Node(int sum,int mini,int maxi){
        this->sum=sum;
        this->mini=mini;
        this->maxi=maxi;
    }
};

class Solution {
public:
    int ans=0;
    Node maxBst(TreeNode* root){
        if(root==NULL){
            return Node(0,INT_MAX,INT_MIN);
        }

        auto l=maxBst(root->left);
        auto r=maxBst(root->right);

        if(l.maxi<root->val && r.mini>root->val){
            ans=max(ans,root->val+l.sum+r.sum);
            return Node((root->val+l.sum+r.sum),min(l.mini,root->val),max(r.maxi,root->val));
        }

        return Node(max(l.sum,r.sum),INT_MIN,INT_MAX);
    }

    

    int maxSumBST(TreeNode* root) {
        auto x=maxBst(root);
        return ans;
    }
};