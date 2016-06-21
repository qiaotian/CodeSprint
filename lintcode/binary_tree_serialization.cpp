/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-21T13:58:27+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-21T13:59:07+08:00
* @License: Free License
*/

/**
Design an algorithm and write code to serialize and deserialize a binary tree. Writing the tree to a file is called 'serialization' and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.

There is no limit of how you deserialize or serialize a binary tree, you only need to make sure you can serialize a binary tree to a string and deserialize this string to the original structure.

Have you met this question in a real interview? Yes
Example
An example of testdata: Binary tree {3,9,20,#,#,15,7}, denote the following structure:

  3
 / \
9  20
  /  \
 15   7
Our data serialization use bfs traversal. This is just for when you got wrong answer and want to debug the input.
You can use other method to do serializaiton and deserialization.
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

 /**
  * Test case allows redundent '####' behind the returned serialized string
  */

class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        string ans = "";
        if(!root) return ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int len = que.size();
            for(int i=0; i<len; i++) {
                TreeNode* tmp = que.front();
                que.pop();
                if(!tmp) {
                    ans+=ans.empty()?"#":",#";
                } else {
                    ans+=ans.empty()?to_string(tmp->val):(','+to_string(tmp->val));
                    que.push(tmp->left);
                    que.push(tmp->right);
                }
            }
        }
        return ans;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
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
