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
        ListNode* temp = head;
        int cnt = 0;
        while (temp) {
            cnt += 1;
            temp = temp->next;
        }
        int need = cnt - n;

        ListNode* temp2 = head;
        int counter = 0;
        if (counter == need) return head->next;
        while (temp2) {
            counter++;
            if (counter == need) {
                temp2->next = temp2->next->next;
            }
            temp2 = temp2->next;
        }
        return head;
    }
};