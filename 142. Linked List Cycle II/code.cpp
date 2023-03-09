/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* s= head;
        ListNode* f= head;
        ListNode* entry= head;

        if(head==NULL || head->next==NULL){
            return NULL;
        }

        while(f->next!=NULL && f->next->next!=NULL){
            s=s->next;
            f=f->next->next;
            
            if(s==f){ // there exists a cycle
            while(s!=entry){
                s=s->next;
                entry=entry->next;
            }
            return entry;
            } 
        }
        return NULL;
    
    }
      
};
