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

    void add(ListNode* &l1, ListNode* &l2, int &carry, ListNode* &dummy){
        if(!l1 || !l2) return; 
        int sum =  l1->val + l2->val + carry;
         carry = sum / 10;
        ListNode* temp = new ListNode(sum % 10);

        dummy->next = temp;
        dummy = dummy->next;
        l1 = l1->next;
        l2 = l2->next;
        add(l1, l2, carry, dummy);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        int carry = 0;
        add(l1, l2, carry, dummy);
        cout<<"ok1";
        while(l1){
            int sum = l1->val + carry;
             carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            dummy->next = temp;
            dummy = dummy->next;
            l1 = l1->next;
        }
        while(l2){
            int sum = l2->val + carry;
            carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            dummy->next = temp;
            dummy = dummy->next;
            l2 = l2->next;
        }
        if(carry){
            ListNode* temp = new ListNode(carry);
            dummy->next = temp;
        }
        return ans->next;
    }
};