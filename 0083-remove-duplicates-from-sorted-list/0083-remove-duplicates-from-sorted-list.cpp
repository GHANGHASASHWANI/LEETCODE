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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head->next;
        ListNode* ans=head;
        while(temp){
            while(temp && ans->val ==temp->val){
                temp=temp->next;
            }
            ans->next=temp;
            ans=temp;
            if(temp) temp=temp->next;
            
        }
        return head;
    }
};