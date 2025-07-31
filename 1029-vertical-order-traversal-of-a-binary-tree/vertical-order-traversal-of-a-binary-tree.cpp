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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<int,pair<int,TreeNode*>>> q;
        q.push({0,{0,root}});
        while(!q.empty()){
            auto temp=q.front();
            int h=temp.second.first;
            int v=temp.first;
            auto node=temp.second.second;
            mp[v][h].insert(node->val);
            q.pop();
            if(node->left)
                q.push({v-1,{h+1,node->left}});
            if(node->right)
                q.push({v+1,{h+1,node->right}});
        }
        for(auto i:mp){
            vector<int> t;
            for(auto j:i.second){
                for(auto k:j.second){
                    t.push_back(k);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};