/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string str="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            if(temp==NULL) str+="#,";
            else
            str+=to_string(temp->val)+',';
            if(temp!=NULL){
            q.push(temp->left);
            q.push(temp->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        queue<TreeNode*> q;
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            getline(ss,str,',');
            if(str=="#"){
                temp->left=NULL;
            }
            else{
                TreeNode* r=new TreeNode(stoi(str));
                temp->left=r;
                q.push(r);
            }
            getline(ss,str,',');
            if(str=="#"){
                temp->right=NULL;
            }
            else{
                TreeNode* l=new TreeNode(stoi(str));
                temp->right=l;
                q.push(l);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));