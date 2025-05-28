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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;

        ListNode* odd = new ListNode(-1);
        ListNode* even = new ListNode(-1);
        ListNode* start1 = odd;
        ListNode* start2 = even;
        ListNode* temp = head;
        bool check = true;
        while (temp) {
            // cout<<temp->val<<" "; 
            if (check) {
                odd->next = new ListNode(temp->val);
                odd = odd->next;
            } else {
                even->next = new ListNode(temp->val);
                even = even->next;
            }
            temp = temp->next;
            check = !check;
        }
        odd->next = start2->next;

        return start1->next;
    }
};