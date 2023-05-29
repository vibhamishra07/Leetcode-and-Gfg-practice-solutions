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
        if(head->next==NULL && n==1 ){
            return NULL;
        }
        
        ListNode *trav=head;
        int size=0;
        
        while(trav!=NULL){
            trav=trav->next;
            size++;
        }
        
        n=size-n;
        int count=1;
        trav=head;
        
//         for deleting first Node from last
        if(n==0){
            head=trav->next;
            trav=NULL;
            delete(trav);
            return head;
        }
        
        
        while(count<n ){
            count++;
            trav=trav->next;
        }
        ListNode* node=trav->next;
        trav->next=trav->next->next;
        node=NULL;
        delete(node);
        
        return head;
        
    }
};