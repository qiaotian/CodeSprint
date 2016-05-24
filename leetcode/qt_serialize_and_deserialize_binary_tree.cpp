/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * Time: 42ms, beats:50%
 *
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root) return ans;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            size_t count = que.size();
            for(int i = 0; i<count; i++) {
                TreeNode *tmp = que.front();
                que.pop();
                if(!tmp) {
                    ans+=ans.empty()?"#":",#";
                } else {
                    ans+=ans.empty()?to_string(tmp->val) : (','+to_string(tmp->val));
                    que.push(tmp->left);
                    que.push(tmp->right);
                }
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        vector<string> container;
        if(data.empty()) return root;

        // split the string data into vector
        int start = 0;
        while(start < data.size()) {
            int index = (int)data.find_first_of(",", start);
            if(index != string::npos){
                container.push_back(data.substr(start, index-start));
                start = index +1;
            } else {
                container.push_back(data.substr(start));
                start = data.size(); // end the loop
            }
        }

        queue<TreeNode*> que;

        int index = 0;
        root = new TreeNode(stoi(container[index++]));
        que.push(root);
        while(!que.empty()) {
            size_t count = que.size();
            for(int i = 0; i<count; i++) {
                TreeNode* tmp = que.front();
                que.pop();

                string ll = container[index++];
                string rr = container[index++];

                if(ll != "#") {
                    tmp->left = new TreeNode(stoi(ll));
                    que.push(tmp->left);
                }
                if(rr != "#") {
                    tmp->right = new TreeNode(stoi(rr));
                    que.push(tmp->right);
                }
            }
        }
        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
