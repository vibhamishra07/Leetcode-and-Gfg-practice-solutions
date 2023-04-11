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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL) return head;
        
        int k=1;
        ListNode* t=head;
        while(t->next!=NULL){
            t=t->next;
            k++;
        }
        if(k==1){
            head=t->next;
            return head;
        }
        int i=1;
        t=head;
        while(i<k-n && t->next!=NULL){
            t=t->next;
            i++;
        }
        if(k-n==0){
            head=t->next;
            return head;
        }
        if(t->next!=NULL){
            ListNode* nextNode=t->next;
            t->next=nextNode->next;
            nextNode=NULL;
            delete nextNode;
        }
        
        return head;
        
        
    }
};