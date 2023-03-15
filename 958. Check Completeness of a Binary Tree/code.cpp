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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool foundNull = false;
        while(!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left)
            {
                if(foundNull)
                    return false;
                q.push(curr->left);
            }
            else
                foundNull = true;
            if(curr->right)
            {
                if(foundNull)
                    return false;
                q.push(curr->right);
            }
            else
                foundNull = true;
        }
        return true;
    }
};
