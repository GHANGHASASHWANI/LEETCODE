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
private:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;

        while (list1 && list2) {
            if(list1->val <= list2->val) {
                dummy->next = list1;
                dummy = dummy->next;
                list1 = list1->next;
            } else {
                dummy->next = list2;
                dummy = dummy->next;
                list2 = list2->next;
            }
        }
        if (list1) dummy->next = list1;
        if (list2) dummy->next = list2;
        
        return ans->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp1 = slow->next;
        slow->next = NULL;

        ListNode* sort1 = sortList(head);
        ListNode* sort2 = sortList(temp1);

        return merge(sort1, sort2);
    }
};