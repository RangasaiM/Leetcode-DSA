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

    void trackParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& mp){
        if(root==NULL) return;
        if(root->left) mp[root->left]=root;
        if(root->right) mp[root->right]=root;
        trackParent(root->left,mp);
        trackParent(root->right,mp);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> mp;
        unordered_set<TreeNode*> vis;
        mp[root]=NULL;
        trackParent(root,mp);
        queue<TreeNode*> q;
        q.push(target);
        vis.insert(target);
        while(!q.empty()){
            if(k==0) break;
            int n=q.size();
            for(int i=0;i<n;i++){
                auto temp=q.front();
                q.pop();
                if(temp->left && vis.find(temp->left)==vis.end()){
                    q.push(temp->left);
                    vis.insert(temp->left);
                }
                if(temp->right && vis.find(temp->right)==vis.end()){
                    q.push(temp->right);
                    vis.insert(temp->right);
                }
                if(mp[temp] && vis.find(mp[temp])==vis.end()){
                    q.push(mp[temp]);
                    vis.insert(mp[temp]);
                }
            }
            k--;
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;

    }
};