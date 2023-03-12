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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
           if (lists.size() == 1)
            return lists[0];
        if (lists.size() == 0)
            return NULL;
        return divideAndConquer(lists, 0, lists.size());   
    }
    
    ListNode *divideAndConquer(vector<ListNode*>& lists, int ini, int fin) {
        // Base case
        if (fin - ini == 1)
            return mergeTwoLists(lists[ini], NULL); // Clone
        else
            return mergeTwoLists(divideAndConquer(lists, ini, (ini+fin)/2), divideAndConquer(lists, (ini+fin)/2, fin));
    }
    
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        /* Out of place algorithm without dummy. This requires a host of if statements */
        ListNode *dummyhead = new ListNode();
        ListNode *sorted = dummyhead;
        ListNode *nextnode = NULL;
        while (list1 != NULL && list2 != NULL) { // If both are nonempty
            // Set nextnode
            if (list1->val <= list2->val) {
                nextnode = new ListNode(list1->val);
                list1 = list1->next;
            }
            else {
                nextnode = new ListNode(list2->val);
                list2 = list2->next;
            }
            // Increment node
            sorted->next = nextnode;
            sorted = sorted->next;
        }
        while (list1 != NULL) { // Append rest of list1
            nextnode = new ListNode(list1->val);
            list1 = list1->next;
            sorted->next = nextnode;
            sorted = sorted->next;
        }
        while (list2 != NULL) { // Append rest of list2
            nextnode = new ListNode(list2->val);
            list2 = list2->next;
            sorted->next = nextnode;
            sorted = sorted->next;
        }
        return dummyhead->next;
    }
};
