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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> map;
        dfs(root, map, res);
        return res;
    }

private:
    string dfs(TreeNode* root, unordered_map<string, int>& map,
               vector<TreeNode*>& res){

        if(!root)
            return "(null)";

        string left = dfs(root->left, map, res);
        string right = dfs(root->right, map, res);
        string hashcode = "(" + left + ")" + to_string(root->val) + "(" + right + ")";

        if(map[hashcode] == 1)
            res.push_back(root);
        map[hashcode] ++;
        return hashcode;
    }
};
