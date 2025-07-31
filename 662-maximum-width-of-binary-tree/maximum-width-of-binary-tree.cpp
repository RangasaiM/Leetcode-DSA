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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        while(!q.empty()){
            int left,right,size=q.size();
            int mmin=q.front().first;
            for(int i=0;i<size;i++){
                long long currid=q.front().first-mmin;
                auto temp=q.front();
                auto node=temp.second;
                q.pop();
                if(i==0) left=currid;
                if(i==size-1) right=currid;
                if(node->left) q.push({(2*(currid)+1),node->left});
                if(node->right) q.push({(2*(currid)+2),node->right});
            }
            ans=max(ans,right+1);
        }
        return ans;
    }
};