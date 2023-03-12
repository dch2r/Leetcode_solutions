/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int size = getSize(head);
        ListNode* current = head;
        return buildBST(current, 0, size - 1);
    }
    
private:
    int getSize(ListNode* head) {
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        return size;
    }
    
    TreeNode* buildBST(ListNode*& current, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = (start + end) / 2;
        TreeNode* left = buildBST(current, start, mid - 1);
        TreeNode* node = new TreeNode(current->val);
        current = current->next;
        TreeNode* right = buildBST(current, mid + 1, end);
        node->left = left;
        node->right = right;
        return node;
    }
};
