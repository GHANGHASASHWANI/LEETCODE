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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* start1 = l1;
        ListNode* start2 = l2;

        ListNode* newHead =  new ListNode(0);
        ListNode* ans = newHead;
        while (start1 && start2 ) {
            int num1 = start1->val;
            int num2 = start2->val;
            int total = num1 + num2 + carry;
            carry = total / 10;
            total = total % 10;
            newHead->next = new ListNode(total);
            newHead = newHead->next;

            start1 = start1->next;
            start2 = start2->next;
        }
        while (start1) {
           int num1 = start1->val;
       
            int total = num1 + carry;
            carry = total / 10;
            total = total % 10;
            newHead->next = new ListNode(total);
            newHead = newHead->next;

            start1 = start1->next;
        }
         while (start2) {
           int num2 = start2->val;
       
            int total = num2 + carry;
            carry = total / 10;
            total = total % 10;
            newHead->next = new ListNode(total);
            newHead = newHead->next;

            start2 = start2->next;
        }
        if (carry) {
            newHead->next = new ListNode(1);
        }
        return ans->next;
    }
};