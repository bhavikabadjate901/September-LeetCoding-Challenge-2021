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
     vector<TreeNode*> recur(int l, int r) {
        if(l > r){
        return {NULL};
        }
        vector<TreeNode*>ans;
        for(int root = l; root <= r; root++){
            vector<TreeNode*>left = recur(l, root -1);
            vector<TreeNode*>right = recur( root + 1 , r);

            for(auto node_l: left){
                for(auto node_r: right){
                    TreeNode* node = new TreeNode(root);
                    node->left = node_l;
                    node->right = node_r;
                    ans.push_back(node);
                }
            }
        }
         return ans;
    }
    
    
    
    vector<TreeNode*> generateTrees(int n) {
        return recur(1,n);
    }
};